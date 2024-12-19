
#include "includes.h"

// Instantiate SHT Temperature/Humidity Sensor
Adafruit_SHT31 sht31 = Adafruit_SHT31(&Wire);

bool init_temperature_sensor ( void )
{
    Serial.println("SHT31 Init");
    MyKeezer.Temp_Display_Units = TEMPERATURE_UNITS_F;

    if (! sht31.begin(0x44)) {   // Set to 0x45 for alternate i2c addr
        Serial.println("Couldn't find SHT31");
        return false;
    }
    else
        return true;
   
}

void read_DHT_temperature_humidity ( void )
{
  sht31.readBoth(&MyKeezer.TemperatureDegC,&MyKeezer.Humidity);
  MyKeezer.TemperatureDegF = (MyKeezer.TemperatureDegC * 1.8) + 32;
}


void update_temperature_info( void )
{
uint16_t temp_color;


    // Change color of Temperature Panel according to temperature
    if ( MyKeezer.TemperatureDegF > 40)
		  lv_obj_set_style_bg_color(objects.pnl_temperature, lv_color_hex(0xff0000), 0);
    else if ( MyKeezer.TemperatureDegF < 35 )
		  lv_obj_set_style_bg_color(objects.pnl_temperature, lv_color_hex(0x0000ff), 0);
    else
		  lv_obj_set_style_bg_color(objects.pnl_temperature, lv_color_hex(0x000000), 0);


    // Update the Label that shows the Temperature
    if (isnan(MyKeezer.TemperatureDegF) ) 
      lv_label_set_text(objects.lbl_keezer_cur_temp, "??.?");
    else
      {
      if (MyKeezer.Temp_Display_Units == TEMPERATURE_UNITS_C)
        lv_label_set_text_fmt(objects.lbl_keezer_cur_temp, "%.1f", MyKeezer.TemperatureDegC);
      else
        lv_label_set_text_fmt(objects.lbl_keezer_cur_temp, "%.1f", MyKeezer.TemperatureDegF);
      }  


}

