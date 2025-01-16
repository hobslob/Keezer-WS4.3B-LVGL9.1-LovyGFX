#include "includes.h"

extern void Save_Scale_Settings_To_NV_Storage ( uint8_t scalenum );


// Instantiate Load Cell Amplifiers
NAU7802 myScales[4]; //Create 4 instances of the NAU7802 class

// Instantiate the I/O Expander that detects cable connection to scale
PCA9536 scale_cable_detector;



void setup_scales ( void )
{
uint8_t scalenum;

  delay(100);
	Serial.println("NAU7802 Init");

  ScaleData[0].I2C_Mux_Port = PCA9548_PORT0;
  ScaleData[1].I2C_Mux_Port = PCA9548_PORT1;
  ScaleData[2].I2C_Mux_Port = PCA9548_PORT2;
  ScaleData[3].I2C_Mux_Port = PCA9548_PORT3;

  NewScaleData[0].I2C_Mux_Port = PCA9548_PORT0;
  NewScaleData[1].I2C_Mux_Port = PCA9548_PORT1;
  NewScaleData[2].I2C_Mux_Port = PCA9548_PORT2;
  NewScaleData[3].I2C_Mux_Port = PCA9548_PORT3;

  KegData[0].sample_index = 0;  
  KegData[1].sample_index = 0;  
  KegData[2].sample_index = 0;  
  KegData[3].sample_index = 0;  

  // Start IO Expander that detects scale cable connection
  if (scale_cable_detector.begin() == false)
  {
    Serial.println("PCA9536 not detected. Please check wiring. Freezing...");
  }

  // Set all 4 IO as input
  for (int i = 0; i < 4; i++)
  {
    // pinMode can be used to set an I/O as OUTPUT or INPUT
    scale_cable_detector.pinMode(i, INPUT);
  }
 

  // Find all Scale ADC's
  for (scalenum=0; scalenum<4; scalenum++)
    {
    Select_I2C_Mux_Port(ScaleData[scalenum].I2C_Mux_Port);
    
    Serial.print("Scale "); Serial.print(scalenum+1);
	  if (! myScales[scalenum].begin(Wire)) 
      {
		  ScaleData[scalenum].isPresent = false;//old
		  NewScaleData[scalenum].isPresent = false;
      Serial.println(" Not Detected");
	    }
    else
      {
		  ScaleData[scalenum].isPresent = true;//old
		  NewScaleData[scalenum].isPresent = true;
    	Serial.println(" Detected");
      }

    }


  // Now check if cables are connected from ADC's to scales using the pullups connected to the IO expander
  for (int i = 0; i < 4; i++)
    {
    if (scale_cable_detector.digitalRead(i) == 0) // connected
      {
      if (NewScaleData[i].isPresent)
        NewScaleData[i].isPresent = true;
      else
        NewScaleData[i].isPresent = false; // connected but ADC is not working/connected
      }
    else
      {
       NewScaleData[i].isPresent = false; // Cable is not connected to Scale, regardless of whether ADC is working
      }
    }


    MyKeezer.isScale1Installed = NewScaleData[0].isPresent;
    MyKeezer.isScale2Installed = NewScaleData[1].isPresent;
    MyKeezer.isScale3Installed = NewScaleData[2].isPresent;
    MyKeezer.isScale4Installed = NewScaleData[3].isPresent;

  // Set opacity of Keg Panels on Main screen based on connectivity status
  if (MyKeezer.isScale1Installed)
      lv_obj_set_style_opa(objects.pnl_keg_container1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  else
      lv_obj_set_style_opa(objects.pnl_keg_container1, 75, LV_PART_MAIN | LV_STATE_DEFAULT);

  if (MyKeezer.isScale2Installed)
      lv_obj_set_style_opa(objects.pnl_keg_container2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  else
      lv_obj_set_style_opa(objects.pnl_keg_container2, 75, LV_PART_MAIN | LV_STATE_DEFAULT);

  if (MyKeezer.isScale3Installed)
      lv_obj_set_style_opa(objects.pnl_keg_container3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  else
      lv_obj_set_style_opa(objects.pnl_keg_container3, 75, LV_PART_MAIN | LV_STATE_DEFAULT);

  if (MyKeezer.isScale4Installed)
      lv_obj_set_style_opa(objects.pnl_keg_container4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  else
      lv_obj_set_style_opa(objects.pnl_keg_container4, 75, LV_PART_MAIN | LV_STATE_DEFAULT);


  // ADC Basic Initializations
  for (scalenum=0; scalenum<4; scalenum++)
    {
    if( ScaleData[scalenum].isPresent )
      {
      Select_I2C_Mux_Port(ScaleData[scalenum].I2C_Mux_Port);
      //Select_I2C_Mux_Port(NewScaleData[scalenum].I2C_Mux_Port);
	    myScales[scalenum].setGain(NAU7802_GAIN_16); //Gain can be set to 1, 2, 4, 8, 16, 32, 64, or 128.
	    //myScales[scalenum].setGain(NAU7802_GAIN_32); //Gain can be set to 1, 2, 4, 8, 16, 32, 64, or 128.
	    myScales[scalenum].setLDO(NAU7802_LDO_3V0); //Set LDO (AVDD) voltage. 3.0V is the best choice for Qwiic
	    myScales[scalenum].setSampleRate(NAU7802_SPS_320); //Increase to max sample rate
      }  
    }

  // Send Saved Calibration Settings to Scales
  for (scalenum=0; scalenum<4; scalenum++)
    {
    if( ScaleData[scalenum].isPresent )
      {
      Select_I2C_Mux_Port(ScaleData[scalenum].I2C_Mux_Port);
      Write_Calibration_Settings_to_Scale ( scalenum );
	    myScales[scalenum].calibrateAFE(); // Re-cal analog front end when we change gain, sample rate, or channel
      }  
    }

  // Initialize Keg Capacities used for calculations
  for (int i = 0; i < 4; i++)
    initialize_keg_capacity ( i );

	
}


void Calibrate_Scale ( uint8_t scalenum )
{
	Serial.println();
	Serial.println();
	Serial.print(F("Scale "));
	Serial.print(scalenum + 1);
	Serial.println(F(" calibration"));

    if( ScaleData[scalenum].isPresent )
      {
      Select_I2C_Mux_Port(ScaleData[scalenum].I2C_Mux_Port);
      }
    else
      {
	    Serial.println(F("Scale Not Present"));
      return;      
      }


	Serial.println(F("Setup scale with no weight on it. Press a key when ready."));
	while (Serial.available()) Serial.read(); //Clear anything in RX buffer
	while (Serial.available() == 0) delay(10); //Wait for user to press key

	myScales[scalenum].calculateZeroOffset(64); //Zero or Tare the scale. Average over 64 readings.
	Serial.print(F("New zero offset: "));
	Serial.println(myScales[scalenum].getZeroOffset());

	Serial.println(F("Place known weight on scale. Press a key when weight is in place and stable."));
	while (Serial.available()) Serial.read(); //Clear anything in RX buffer
	while (Serial.available() == 0) delay(10); //Wait for user to press key

	Serial.print(F("Please enter the weight, without units, currently sitting on the scale (for example '4.25'): "));
	while (Serial.available()) Serial.read(); //Clear anything in RX buffer
	while (Serial.available() == 0) delay(10); //Wait for user to press key

	//Read user input
	float weightOnScale = Serial.parseFloat();
	Serial.println();

	myScales[scalenum].calculateCalibrationFactor(weightOnScale, 64); //Tell the library how much weight is currently on it
	Serial.print(F("New cal factor: "));
	Serial.println(myScales[scalenum].getCalibrationFactor(), 2);

    ScaleData[scalenum].CalibrationFactor = myScales[scalenum].getCalibrationFactor();
    ScaleData[scalenum].ZeroOffset = myScales[scalenum].getZeroOffset();

	Serial.print(F("New Scale Reading: "));
	Serial.println(myScales[scalenum].getWeight(), 2);

	//recordSystemSettings(); //Commit these values to NV Storage
    Save_Scale_Settings_To_NV_Storage( scalenum );

}



void Write_Calibration_Settings_to_Scale ( uint8_t scalenum )
{

	myScales[scalenum].setCalibrationFactor( ScaleData[scalenum].CalibrationFactor );
	myScales[scalenum].setZeroOffset( ScaleData[scalenum].ZeroOffset );

}


float Get_Instantaneous_Weight ( uint8_t keg_num )
{

  Select_I2C_Mux_Port(NewScaleData[keg_num].I2C_Mux_Port);

  if( NewScaleData[keg_num].isPresent )
    {
      if(myScales[keg_num].available() == true)
          {
          return (myScales[keg_num].getWeight());
          }
      else
        {
        // Return current weight if busy
        return (KegData[keg_num].CurrentWeight);  
        }
    }
  else
    return (0.0);

}


void Get_Keg_Weight ( uint8_t keg_num )
{
float current_weight;
float avgWeight;
uint8_t sampleidx;


  Select_I2C_Mux_Port(NewScaleData[keg_num].I2C_Mux_Port);

      if( NewScaleData[keg_num].isPresent )
        {
        if(myScales[keg_num].available() == true)
          {
          sampleidx = KegData[keg_num].sample_index;  
          current_weight = myScales[keg_num].getWeight();

          KegData[keg_num].sampledata[sampleidx] = current_weight;
    	  
          avgWeight = 0;
        
          for (int x = 0 ; x < NUM_WEIGHT_SAMPLES ; x++)
            avgWeight += KegData[keg_num].sampledata[x];

          avgWeight /= NUM_WEIGHT_SAMPLES;
          KegData[keg_num].CurrentWeight = avgWeight;
          }

        Calculate_Remainig_Content(&KegData[keg_num]);
        }
      

    if(++sampleidx >= NUM_WEIGHT_SAMPLES) 
      sampleidx = 0;

    KegData[keg_num].sample_index = sampleidx;  


}


void Calculate_New_Zero_Offset(uint8_t scalenum)
{

	myScales[scalenum].calculateZeroOffset(64); //Zero or Tare the scale. Average over 64 readings.
	Serial.print(F("New zero offset: "));
	Serial.println(myScales[scalenum].getZeroOffset());

}

void Calculate_New_Cal_Factor(uint8_t scalenum, float weightOnScale)
{

	myScales[scalenum].calculateCalibrationFactor(weightOnScale, 64); //Tell the library how much weight is currently on it
	Serial.print(F("New cal factor: "));
	Serial.println(myScales[scalenum].getCalibrationFactor(), 2);

	Serial.print(F("New Scale Weight Reading: "));
	Serial.println(myScales[scalenum].getWeight(), 2);

}

void ReCalibrate_Scale_AFE (uint8_t scalenum)
{
  Select_I2C_Mux_Port(ScaleData[scalenum].I2C_Mux_Port);
  Write_Calibration_Settings_to_Scale ( scalenum );
  myScales[scalenum].calibrateAFE(); // Re-cal analog front end when we change gain, sample rate, or channel
}

void Read_Calibration_Settings_from_Scale (uint8_t scalenum)
{
    ScaleData[scalenum].CalibrationFactor = myScales[scalenum].getCalibrationFactor();
    ScaleData[scalenum].ZeroOffset = myScales[scalenum].getZeroOffset();

}