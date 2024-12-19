/*
    Driver for CHG422G IO Expander on Waveshare ESP32 Touch 4.3B board

    Breaks the dependency on the Espressif ESP32_IO_Expander library and uses the standare Adruino Wire library instead.
    Reverse engineered the CHG422G.cpp in the Espressif ESP32_IO_Expander library v0.0.4 to find the Register #'s.
    They're not really register numbers, they are actually I2C Addresses. The chip uses multiple I2C Addresses rather
    than a Base I2C Address and multiple registers.  Pretty crappy IMHO.

 * ## Troubleshooting
 *
 * The driver initialization by default sets CH422G's IO0-7 to output high-level mode.
  Since the input/output mode of CH422G's IO0-7 must remain consistent, the driver will only set IO0-7 to
  input mode when it determines that all pins are configured as input.
  Using pinMode and multiPinMode will be invalid. You can only set the pin working mode through enableAllIO_Input,
  enableAllIO_Output, enableOC_PushPull and enableOC_OpenDrain
 *
#define REG_WR_SET_DEFAULT_VAL  (0x01UL)
    // Bit:        |  7  |  6  |  5  |  4  |    3    |    2    |    1     |    0    |
    //             | --- | --- | --- | --- | ------- | ------- | -------- | ------- |
    // Value:      |  /  |  /  |  /  |  /  | [SLEEP] | [OD_EN] | [A_SCAN] | [IO_OE] |
    //             | --- | --- | --- | --- | ------- | ------- | -------- | ------- |
    // Default:    |  0  |  0  |  0  | 0   |    0    |    0    |    0     |    1    |


*/

#include "WS43B_CHG422G.h"

// put function definitions here:
void init_CHG422G( void ) {

  // Initialize the CHG422G IO Expander on Waveshare ESP32 Touch 4.3B board

  // Set IO pin directions
  Wire.beginTransmission(CH422G_REG_WR_SET);
  Wire.write(DIR_REG_DEFAULT_VAL);
  Wire.endTransmission(); 


  // Write default values (HIGH) to the IO Port
  Wire.beginTransmission(CH422G_REG_WR_IO);
  Wire.write(DEASSERT_TP_RST_LCD_RST);
  Wire.endTransmission(); 
  delay(100);


  // GT911 initialization, must be added, otherwise the touch screen will not be recognized  
  // Drive the TP and LCD Reset Pins LOW
  Wire.beginTransmission(CH422G_REG_WR_IO);
  Wire.write(ASSERT_TP_RST_LCD_RST);
  Wire.endTransmission(); 
  delay(100);


  // Release the TP and LCD Reset Pins (Set HIGH)
  Wire.beginTransmission(CH422G_REG_WR_IO);
  Wire.write(DEASSERT_TP_RST_LCD_RST);
  Wire.endTransmission(); 

}

