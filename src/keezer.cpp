#include "includes.h"

// Instantiate NV Storage
Preferences NVstorage;

void init_keezer (void)
{
     // Initialize Temperature Sensor SHT31
    MyKeezer.isTempControllerInstalled = init_temperature_sensor ();
    MyKeezer.TemperatureDegF = 0;

    Read_Settings_From_NV_Storage();

    setup_scales();

    WiFi_Setup();
    if (MyKeezer.isWiFiConnected)
    {
    MDNS_Setup();
    Setup_OTA_Updater();
    Setup_Async_Webserver();

    // Connect to NTP Server and initialize (pseudo?)RTC	
    // Get the POSIX style TZ format string from  https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
    initTime("EST5EDT,M3.2.0,M11.1.0");   // Set for America/New_York
    printLocalTime();
    }

    Detect_Kegs();

    update_all_kegnames();

    hardware_initialized = true;

    delay(500);

    // lv_disp_load_scr(ui_scnHome);
    // lv_obj_del(ui_scnSplash);
    loadScreen(SCREEN_ID_SCN_HOME);
 
}

void Select_I2C_Mux_Port(uint8_t port_select) 
{ 
  Wire.beginTransmission(PCA9548_7BIT_ADDR);
  Wire.write(port_select);
  Wire.endTransmission(); 
}


// Get Sensor Readings and return JSON object
String getSensorReadingsJSON(){
  String jsonString;
 
  readings["temperature"]     = String(MyKeezer.TemperatureDegF); //
  readings["humidity"]        = String(MyKeezer.Humidity); //
  readings["keg1Ounces"]      =  String(KegData[KEG1].remainingTotalOz,1);
  readings["keg1Weight"]      =  String(KegData[KEG1].CurrentWeight,2);
  readings["keg1Contentname"] =  String(KegData[KEG1].ContentName);
  readings["keg2Ounces"]      =  String(KegData[KEG2].remainingTotalOz,1);
  readings["keg2Weight"]      =  String(KegData[KEG2].CurrentWeight,2);
  readings["keg2Contentname"] =  String(KegData[KEG2].ContentName);
  readings["keg3Ounces"]      =  String(KegData[KEG3].remainingTotalOz,1);
  readings["keg3Weight"]      =  String(KegData[KEG3].CurrentWeight,2);
  readings["keg3Contentname"] =  String(KegData[KEG3].ContentName);
  readings["keg4Ounces"]      =  String(KegData[KEG4].remainingTotalOz,1);
  readings["keg4Weight"]      =  String(KegData[KEG4].CurrentWeight,2);
  readings["keg4Contentname"] =  String(KegData[KEG4].ContentName);
 
  serializeJson(readings, jsonString);

  return jsonString;
}



void Detect_Kegs ( void )
{
  // Keg #1
  if (!MyKeezer.isScale1Installed)
    KegData[KEG1].isPresent = false;
  else
    {
    if ( Get_Instantaneous_Weight(KEG1) > 1)
      KegData[KEG1].isPresent = true;
    else
      KegData[KEG1].isPresent = false;
    }

  // Keg #2
  if (!MyKeezer.isScale2Installed)
    KegData[KEG2].isPresent = false;
  else
    {
    if ( Get_Instantaneous_Weight(KEG2) > 1)
      KegData[KEG2].isPresent = true;
    else
      KegData[KEG2].isPresent = false;
    }

  // Keg #3
  if (!MyKeezer.isScale3Installed)
    KegData[KEG3].isPresent = false;
  else
    {
    if ( Get_Instantaneous_Weight(KEG3) > 1)
      KegData[KEG3].isPresent = true;
    else
      KegData[KEG3].isPresent = false;
    }

  // Keg #4
  if (!MyKeezer.isScale4Installed)
    KegData[KEG4].isPresent = false;
  else
    {
    if ( Get_Instantaneous_Weight(KEG4) > 1)
      KegData[KEG4].isPresent = true;
    else
      KegData[KEG4].isPresent = false;
    }

}



void Calculate_Remainig_Content (KegInfo *keg)
{
  keg->remainingTotalOz = (keg->CurrentWeight-keg->EmptyWeight) * BEER_OZ_PER_LB;

  // check for negative content
  if ( keg->remainingTotalOz < 0)
    keg->remainingTotalOz = 0;

  keg->Remaining16oz = keg->remainingTotalOz / 16;
  keg->Remaining12oz = keg->remainingTotalOz / 12;
  keg->PercentFull = (keg->CurrentWeight/keg->FullWeight)*100;

  // check for negative content
  if ( keg->PercentFull < 0)
    keg->PercentFull = 0;


  // Serial.printf("Curr: %f", keg->CurrentWeight);
  // Serial.printf(" Empty: %f", keg->EmptyWeight);
  // Serial.println(" remain");

}



void Read_Settings_From_NV_Storage ( void )
{

  // Open our Namespace in NV
	if (!NVstorage.begin("keezer-app", false))	// open namespace with RW permissions
		Serial.println("Failed to open NVstorage");

  // Read Scale 1 Settings. If a key hasn't been written yet, write a default value

  // KegType type
  if (NVstorage.isKey("s1_KegType") == false)
		NVstorage.putUChar("s1_KegType", 0 ); //Default to 0
  else
    KegData[0].KegType = NVstorage.getUChar("s1_KegType", 0 );     
    //KegData[0].KegType = 2; // sixtel    

  if (NVstorage.isKey("s2_KegType") == false)
		NVstorage.putUChar("s2_KegType", 0 ); //Default to 0
  else
    KegData[1].KegType = NVstorage.getUChar("s2_KegType", 0 );     

  if (NVstorage.isKey("s3_KegType") == false)
		NVstorage.putUChar("s3_KegType", 0 ); //Default to 0
  else
    KegData[2].KegType = NVstorage.getUChar("s3_KegType", 0 );     

  if (NVstorage.isKey("s4_KegType") == false)
		NVstorage.putUChar("s4_KegType", 0 ); //Default to 0
  else
    KegData[3].KegType = NVstorage.getUChar("s4_KegType", 0 );     



  // Calibration Factor
  if (NVstorage.isKey("s1_calfactor") == false)
		NVstorage.putFloat("s1_calfactor", 1.0 ); //Default to 1.0
  else
    ScaleData[0].CalibrationFactor = NVstorage.getFloat("s1_calfactor", 1.0 );     

  if (NVstorage.isKey("s2_calfactor") == false)
		NVstorage.putFloat("s2_calfactor", 1.0 ); //Default to 1.0
  else
    ScaleData[1].CalibrationFactor = NVstorage.getFloat("s2_calfactor", 1.0 );     

  if (NVstorage.isKey("s3_calfactor") == false)
		NVstorage.putFloat("s3_calfactor", 1.0 ); //Default to 1.0
  else
    ScaleData[2].CalibrationFactor = NVstorage.getFloat("s3_calfactor", 1.0 );     

  if (NVstorage.isKey("s4_calfactor") == false)
		NVstorage.putFloat("s4_calfactor", 1.0 ); //Default to 1.0
  else
    ScaleData[3].CalibrationFactor = NVstorage.getFloat("s4_calfactor", 1.0 );     



  // Zero Offset Factor
  if (NVstorage.isKey("s1_zoffset") == false)
		NVstorage.putLong("s1_zoffset", 1.0 ); //Default to 1.0
  else
    ScaleData[0].ZeroOffset = NVstorage.getLong("s1_zoffset", 0 );     

  if (NVstorage.isKey("s2_zoffset") == false)
		NVstorage.putLong("s2_zoffset", 1.0 ); //Default to 1.0
  else
    ScaleData[1].ZeroOffset = NVstorage.getLong("s2_zoffset", 0 );     

  if (NVstorage.isKey("s3_zoffset") == false)
		NVstorage.putLong("s3_zoffset", 1.0 ); //Default to 1.0
  else
    ScaleData[2].ZeroOffset = NVstorage.getLong("s3_zoffset", 0 );     

  if (NVstorage.isKey("s4_zoffset") == false)
		NVstorage.putLong("s4_zoffset", 1.0 ); //Default to 1.0
  else
    ScaleData[3].ZeroOffset = NVstorage.getLong("s4_zoffset", 0 );     



  // Empty Weight
  if (NVstorage.isKey("s1_EmptyWeight") == false)
		NVstorage.putFloat("s1_EmptyWeight", 15.0 ); //Default to 1.0
  else
    KegData[0].EmptyWeight = NVstorage.getFloat("s1_EmptyWeight", 15.0 );     
    //KegData[0].EmptyWeight = 0.1; // test using pitcher     

  if (NVstorage.isKey("s2_EmptyWeight") == false)
		NVstorage.putFloat("s2_EmptyWeight", 15.0 ); //Default to 1.0
  else
    KegData[1].EmptyWeight = NVstorage.getFloat("s2_EmptyWeight", 15.0 );     

  if (NVstorage.isKey("s3_EmptyWeight") == false)
		NVstorage.putFloat("s3_EmptyWeight", 15.0 ); //Default to 1.0
  else
    KegData[2].EmptyWeight = NVstorage.getFloat("s3_EmptyWeight", 15.0 );     

  if (NVstorage.isKey("s4_EmptyWeight") == false)
		NVstorage.putFloat("s4_EmptyWeight", 15.0 ); //Default to 1.0
  else
    KegData[3].EmptyWeight = NVstorage.getFloat("s4_EmptyWeight", 15.0 );     




  // Full Weight
  if (NVstorage.isKey("s1_FullWeight") == false)
		NVstorage.putFloat("s1_FullWeight", 58.0 ); //Default to 1.0
  else
    KegData[0].FullWeight = NVstorage.getFloat("s1_FullWeight", 58.0 );     

  if (NVstorage.isKey("s2_FullWeight") == false)
		NVstorage.putFloat("s2_FullWeight", 58.0 ); //Default to 1.0
  else
    KegData[1].FullWeight = NVstorage.getFloat("s2_FullWeight", 58.0 );     

  if (NVstorage.isKey("s3_FullWeight") == false)
		NVstorage.putFloat("s3_FullWeight", 58.0 ); //Default to 1.0
  else
    KegData[2].FullWeight = NVstorage.getFloat("s3_FullWeight", 58.0 );     

  if (NVstorage.isKey("s4_FullWeight") == false)
		NVstorage.putFloat("s4_FullWeight", 58.0 ); //Default to 1.0
  else
    KegData[3].FullWeight = NVstorage.getFloat("s4_FullWeight", 58.0 );     



  // Content type
  if (NVstorage.isKey("s1_ContentType") == false)
		NVstorage.putUChar("s1_ContentType", 0 ); //Default to 0
  else
    KegData[0].ContentType = NVstorage.getUChar("s1_ContentType", 0 );     

  if (NVstorage.isKey("s2_ContentType") == false)
		NVstorage.putUChar("s2_ContentType", 0 ); //Default to 0
  else
    KegData[1].ContentType = NVstorage.getUChar("s2_ContentType", 0 );     

  if (NVstorage.isKey("s3_ContentType") == false)
		NVstorage.putUChar("s3_ContentType", 0 ); //Default to 0
  else
    KegData[2].ContentType = NVstorage.getUChar("s3_ContentType", 0 );     

  if (NVstorage.isKey("s4_ContentType") == false)
		NVstorage.putUChar("s4_ContentType", 0 ); //Default to 0
  else
    KegData[3].ContentType = NVstorage.getUChar("s4_ContentType", 0 );     



  // Keg Name
  if (NVstorage.isKey("s1_KegName") == false)
		NVstorage.putString("s1_KegName", "Keg1" ); //Default to Keg1
  else
    KegData[0].KegName = NVstorage.getString("s1_KegName", "Keg1" );     

  if (NVstorage.isKey("s2_KegName") == false)
		NVstorage.putString("s2_KegName", "Keg2" ); //Default to Keg2
  else
    KegData[1].KegName = NVstorage.getString("s2_KegName", "Keg2" );     

  if (NVstorage.isKey("s3_KegName") == false)
		NVstorage.putString("s3_KegName", "Keg3" ); //Default to Keg3
  else
    KegData[2].KegName = NVstorage.getString("s3_KegName", "Keg3" );     

  if (NVstorage.isKey("s4_KegName") == false)
		NVstorage.putString("s4_KegName", "Keg4" ); //Default to Keg4
  else
    KegData[3].KegName = NVstorage.getString("s4_KegName", "Keg4" );     



  // Content Name
  if (NVstorage.isKey("s1_ContentName") == false)
		NVstorage.putString("s1_ContentName", "Yummy Beer" ); //Default to Yummy Beer
  else
    KegData[0].ContentName = NVstorage.getString("s1_ContentName", "Yummy Beer" );     

  if (NVstorage.isKey("s2_ContentName") == false)
		NVstorage.putString("s2_ContentName", "Good Beer" ); //Default to Good Beer
  else
    KegData[1].ContentName = NVstorage.getString("s2_ContentName", "Good Beer" );     

  if (NVstorage.isKey("s3_ContentName") == false)
		NVstorage.putString("s3_ContentName", "Meh" ); //Default to Meh
  else
    KegData[2].ContentName = NVstorage.getString("s3_ContentName", "Meh" );     

  if (NVstorage.isKey("s4_ContentName") == false)
		NVstorage.putString("s4_ContentName", "Swill" ); //Default to 1.0
  else
    KegData[3].ContentName = NVstorage.getString("s4_ContentName", "Swill" );     



  // WiFi Info 
  if (NVstorage.isKey("WiFi_SSID") == false)
		NVstorage.putString("WiFi_SSID", "WeBleedBlue" ); //Default to ???
  else
    MyKeezer.WiFiSSID = NVstorage.getString("WiFi_SSID", "WeBleedBlue");     

  if (NVstorage.isKey("WiFi_PWD") == false)
		NVstorage.putString("WiFi_PWD", "Mess11Gra9Ric35" ); //Default to ??
  else
    MyKeezer.WiFiPWD = NVstorage.getString("WiFi_PWD", "Mess11Gra9Ric35");     


	// Close the NV Storage
	NVstorage.end();


  // Debug pause
  delay(1000);

		Serial.print("Keg Type = ");      Serial.println(KegData[0].KegType);
		Serial.print("Cal Factor = ");    Serial.println(ScaleData[0].CalibrationFactor);
		Serial.print("Zero Offset = ");   Serial.println(ScaleData[0].ZeroOffset);
		Serial.print("Empty Weight = ");  Serial.println(KegData[0].EmptyWeight);
		Serial.print("Full Weight = ");   Serial.println(KegData[0].FullWeight);
		Serial.print("Content Type = ");  Serial.println(KegData[0].ContentType);
		Serial.print("Keg Name = ");      Serial.println(KegData[0].KegName);
		Serial.print("Content Name = ");  Serial.println(KegData[0].ContentName);


}


void Save_Scale_Settings_To_NV_Storage ( uint8_t scalenum )
{
  // Open our Namespace in NV
	if (!NVstorage.begin("keezer-app", false))	// open namespace with RW permissions
		Serial.println("Failed to open NVstorage");

    switch ( scalenum )
    {
    case ( SCALE1 ):
      NVstorage.putUChar("s1_KegType",      KegData[scalenum].KegType ); 
      NVstorage.putFloat("s1_calfactor",    ScaleData[scalenum].CalibrationFactor );
      NVstorage.putLong("s1_zoffset",       ScaleData[scalenum].ZeroOffset );
      NVstorage.putFloat("s1_EmptyWeight",  KegData[scalenum].EmptyWeight );
      NVstorage.putFloat("s1_FullWeight",   KegData[scalenum].FullWeight );
      NVstorage.putUChar("s1_ContentType",  KegData[scalenum].ContentType ); 
      NVstorage.putString("s1_KegName",     KegData[scalenum].KegName );
      NVstorage.putString("s1_ContentName", KegData[scalenum].ContentName );
      break;

    case ( SCALE2 ):
      NVstorage.putUChar("s2_KegType",      KegData[scalenum].KegType ); 
      NVstorage.putFloat("s2_calfactor",    ScaleData[scalenum].CalibrationFactor );
      NVstorage.putLong("s2_zoffset",       ScaleData[scalenum].ZeroOffset );
      NVstorage.putFloat("s2_EmptyWeight",  KegData[scalenum].EmptyWeight );
      NVstorage.putFloat("s2_FullWeight",   KegData[scalenum].FullWeight );
      NVstorage.putUChar("s2_ContentType",  KegData[scalenum].ContentType ); 
      NVstorage.putString("s2_KegName",     KegData[scalenum].KegName );
      NVstorage.putString("s2_ContentName", KegData[scalenum].ContentName );
      break;

    case ( SCALE3 ):
      NVstorage.putUChar("s3_KegType",      KegData[scalenum].KegType ); 
      NVstorage.putFloat("s3_calfactor",    ScaleData[scalenum].CalibrationFactor );
      NVstorage.putLong("s3_zoffset",       ScaleData[scalenum].ZeroOffset );
      NVstorage.putFloat("s3_EmptyWeight",  KegData[scalenum].EmptyWeight );
      NVstorage.putFloat("s3_FullWeight",   KegData[scalenum].FullWeight );
      NVstorage.putUChar("s3_ContentType",  KegData[scalenum].ContentType ); 
      NVstorage.putString("s3_KegName",     KegData[scalenum].KegName );
      NVstorage.putString("s3_ContentName", KegData[scalenum].ContentName );
      break;

    case ( SCALE4 ):
      NVstorage.putUChar("s4_KegType",      KegData[scalenum].KegType ); 
      NVstorage.putFloat("s4_calfactor",    ScaleData[scalenum].CalibrationFactor );
      NVstorage.putLong("s4_zoffset",       ScaleData[scalenum].ZeroOffset );
      NVstorage.putFloat("s4_EmptyWeight",  KegData[scalenum].EmptyWeight );
      NVstorage.putFloat("s4_FullWeight",   KegData[scalenum].FullWeight );
      NVstorage.putUChar("s4_ContentType",  KegData[scalenum].ContentType ); 
      NVstorage.putString("s4_KegName",     KegData[scalenum].KegName );
      NVstorage.putString("s4_ContentName", KegData[scalenum].ContentName );
      break;

    default:
      break;
    }

	// Close the NV Storage
	NVstorage.end();

}


void Save_Kegname_To_NVStorage ( uint8_t kegnum )
{
  // Open our Namespace in NV
	if (!NVstorage.begin("keezer-app", false))	// open namespace with RW permissions
		Serial.println("Failed to open NVstorage");

    switch ( kegnum )
    {
    case ( SCALE1 ):
      NVstorage.putString("s1_ContentName", KegData[kegnum].ContentName );
      break;

    case ( SCALE2 ):
      NVstorage.putString("s2_ContentName", KegData[kegnum].ContentName );
      break;

    case ( SCALE3 ):
      NVstorage.putString("s3_ContentName", KegData[kegnum].ContentName );
      break;

    case ( SCALE4 ):
      NVstorage.putString("s4_ContentName", KegData[kegnum].ContentName );
      break;

    default:
      break;
    }

	// Close the NV Storage
	NVstorage.end();

}


void Save_WiFi_To_NVStorage ( void )
{
  // Open our Namespace in NV
	if (!NVstorage.begin("keezer-app", false))	// open namespace with RW permissions
		Serial.println("Failed to open NVstorage");

  //NVstorage.putString("s1_ContentName", KegData[kegnum].ContentName );
	NVstorage.putString("WiFi_SSID", MyKeezer.WiFiSSID ); //Default to ???
	NVstorage.putString("WiFi_PWD", MyKeezer.WiFiPWD ); //Default to ??

	// Close the NV Storage
	NVstorage.end();

}


void update_all_kegnames ( void )
{

  // Update Keg1 Name textbox
  lv_label_set_text(objects.lbl_keg_name1, KegData[0].ContentName.c_str());		

  // Update Keg1 Name textbox
  lv_label_set_text(objects.lbl_keg_name2, KegData[1].ContentName.c_str());		

  // Update Keg1 Name textbox
  lv_label_set_text(objects.lbl_keg_name3, KegData[2].ContentName.c_str());		

  // Update Keg1 Name textbox
  lv_label_set_text(objects.lbl_keg_name4, KegData[3].ContentName.c_str());		
}


//void Populate_Kegdata_Canvas (uint8_t kegnum)
void Update_MainScreen_Kegdata (uint8_t kegnum)
{

  // Update % Remaining Bar
  //int32_t remain_pct = (int32_t)KegData[kegnum].PercentFull;
  lv_color_t my_red = lv_color_hex(0xFF0000);
  lv_color_t my_yellow = lv_color_hex(0xE0FF00);
  lv_color_t my_std_border = lv_color_hex(0x414141);
  lv_color_t border_color;


  switch (kegnum)
    {
    case 0:
      //Serial.println("Scale1");
      // Update % Remaining Bar
      //lv_bar_set_value(objects.bar_keg_remain1, (int32_t)KegData[kegnum].PercentFull, LV_ANIM_OFF);

      // Update 16oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg16oz_remain1, "%.0f", KegData[kegnum].Remaining16oz);
      //lv_label_set_text_fmt(objects.lbl_keg16oz_remain1, "%d", (uint32_t)KegData[kegnum].Remaining16oz);

      // Update 12oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg12oz_remain1, "%.0f", KegData[kegnum].Remaining12oz);

      // Update Color of % Remaining Bar and Keg Container
      //border_color = lv_obj_get_style_border_color(objects.pnl_keg_container1,LV_PART_MAIN);
      // if ( KegData[kegnum].PercentFull < 15)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0xFF0000), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xFF0000), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_red) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0xFF0000), LV_PART_MAIN);
      //   }
      // else if ( KegData[kegnum].PercentFull < 25)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0xE0FF00), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xE0FF00), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_yellow) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0xE0FF00), LV_PART_MAIN);
      //   }
      // else
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0x2095f6), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_std_border) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0x414141), LV_PART_MAIN);
      //   }

      break;

    case 1:
      //Serial.println("Scale2");
      // Update % Remaining Bar
      //lv_bar_set_value(objects.bar_keg_remain2, (int32_t)KegData[kegnum].PercentFull, LV_ANIM_OFF);

      // Update 16oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg16oz_remain2, "%.0f", KegData[kegnum].Remaining16oz);

      // Update 12oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg12oz_remain2, "%.0f", KegData[kegnum].Remaining12oz);

      // Update Color of % Remaining Bar and Keg Container
      //border_color = lv_obj_get_style_border_color(objects.pnl_keg_container2,LV_PART_MAIN);
      // if ( KegData[kegnum].PercentFull < 15)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain2, lv_color_hex(0xFF0000), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain2, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain2, lv_color_hex(0xFF0000), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_red) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container2, lv_color_hex(0xFF0000), LV_PART_MAIN);
      //   }
      // else if ( KegData[kegnum].PercentFull < 25)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain2, lv_color_hex(0xE0FF00), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain2, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain2, lv_color_hex(0xE0FF00), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_yellow) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container2, lv_color_hex(0xE0FF00), LV_PART_MAIN);
      //   }
      // else
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain2, lv_color_hex(0x2095f6), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain2, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain2, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_std_border) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container2, lv_color_hex(0x414141), LV_PART_MAIN);
      //   }

      break;

    case 2:
      //Serial.println("Scale3");
      // Update % Remaining Bar
      //lv_bar_set_value(objects.bar_keg_remain3, (int32_t)KegData[kegnum].PercentFull, LV_ANIM_OFF);

      // Update 16oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg16oz_remain3, "%.0f", KegData[kegnum].Remaining16oz);

      // Update 12oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg12oz_remain3, "%.0f", KegData[kegnum].Remaining12oz);

      // Update Color of % Remaining Bar and Keg Container
      //border_color = lv_obj_get_style_border_color(objects.pnl_keg_container3,LV_PART_MAIN);
      // if ( KegData[kegnum].PercentFull < 15)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain3, lv_color_hex(0xFF0000), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain3, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain3, lv_color_hex(0xFF0000), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_red) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container3, lv_color_hex(0xFF0000), LV_PART_MAIN);
      //   }
      // else if ( KegData[kegnum].PercentFull < 25)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain3, lv_color_hex(0xE0FF00), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain3, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain3, lv_color_hex(0xE0FF00), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_yellow) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container3, lv_color_hex(0xE0FF00), LV_PART_MAIN);
      //   }
      // else
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain3, lv_color_hex(0x2095f6), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain3, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain3, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_std_border) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container3, lv_color_hex(0x414141), LV_PART_MAIN);
      //   }

      break;

    case 3:
      //Serial.println("Scale4");
      // Update % Remaining Bar
      //lv_bar_set_value(objects.bar_keg_remain4, (int32_t)KegData[kegnum].PercentFull, LV_ANIM_OFF);

      // Update 16oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg16oz_remain4, "%.0f", KegData[kegnum].Remaining16oz);

      // Update 12oz remaining data label
      lv_label_set_text_fmt(objects.lbl_keg12oz_remain4, "%.0f", KegData[kegnum].Remaining12oz);

      // Update Color of % Remaining Bar and Keg Container
      //border_color = lv_obj_get_style_border_color(objects.pnl_keg_container4,LV_PART_MAIN);
      // if ( KegData[kegnum].PercentFull < 15)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain4, lv_color_hex(0xFF0000), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain4, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain4, lv_color_hex(0xFF0000), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_red) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container4, lv_color_hex(0xFF0000), LV_PART_MAIN);
      //   }
      // else if ( KegData[kegnum].PercentFull < 25)
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain4, lv_color_hex(0xE0FF00), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain4, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain4, lv_color_hex(0xE0FF00), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_yellow) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container4, lv_color_hex(0xE0FF00), LV_PART_MAIN);
      //   }
      // else
      //   {
      //   lv_obj_set_style_bg_color(objects.bar_keg_remain4, lv_color_hex(0x2095f6), LV_PART_INDICATOR);
      //   lv_obj_set_style_bg_opa(objects.bar_keg_remain4, 255, LV_PART_INDICATOR);
      //   lv_obj_set_style_text_color(objects.lbl_keg_pct_remain4, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

      //   if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_std_border) )
      //     lv_obj_set_style_border_color(objects.pnl_keg_container4, lv_color_hex(0x414141), LV_PART_MAIN);
      //   }

      break;

    default:
      break;
    }

}



void Update_pnl_keg_Info( void ) 
{
  // Update the keg weight and remaining fl oz of the active keg tab

  // Get the active Tab
  uint16_t kegnum = lv_tabview_get_tab_act(objects.tab_view1);

  lv_label_set_text_fmt(objects.lbl_keg_remain_total_data, "%.0f fl oz", KegData[kegnum].remainingTotalOz);
  lv_label_set_text_fmt(objects.lbl_keg_weight_data, "%.1f lbs", KegData[kegnum].CurrentWeight);

}

void Update_pnl_keg_capacity ( uint8_t kegnum )
{
  uint8_t kegtype = KegData[kegnum].KegType;
  lv_label_set_text_fmt(objects.lbl_keg_capacity_data, "%.0f fl oz", keg_capacities[kegtype]);
}
