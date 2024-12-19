#ifndef INC_INCLUDES_H_
#define INC_INCLUDES_H_

/*
// initial testing includes
#include <SPI.h>    // Adafruit BusIO needs this
#include <Wire.h>    // Adafruit BusIO needs this
#include "Adafruit_SHT31.h"
#include "config.h"
#include "globals.h"
#include "temp_hum.h"
#include "LittleFS.h"
#include <Preferences.h>	// NV Storage Library in ESP32 Flash
#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h"
// Includes for WiFi, Webserver & WebUpdater
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"
#include "time.h"
#include "wifi-settings.h"

#include "keezer.h"
#include "scale.h"
#include "localtime.h"
#include "networking.h"


#include <./ui/ui.h>
*/




#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <WS43B_CHG422G.h>
#include <TAMC_GT911.h>
#include "Adafruit_SHT31.h"
#include <Preferences.h>	// NV Storage Library in ESP32 Flash
#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h"
#include "LittleFS.h"
//#include <Arduino_GFX_Library.h>
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>


// Includes for WiFi, Webserver & WebUpdater
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"
#include "time.h"
#include "wifi-settings.h"

#include "config.h"
#include "globals.h"

#include "keezer.h"
#include "scale.h"
#include "temp_hum.h"
#include "localtime.h"
#include "networking.h"

#include "BmpClass.h"

#include <lvgl.h>
//#include <demos/lv_demos.h>

#include <./ui/ui.h>




/*
#include <Arduino.h>
#include <Wire.h>
#include <Preferences.h>	// NV Storage Library in ESP32 Flash
#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h"
#include "LittleFS.h"

// Includes for WiFi, Webserver & WebUpdater
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"
#include "time.h"
#include "wifi-settings.h"

#include "config.h"
#include "globals.h"

#include "keezer.h"
#include "scale.h"
#include "temp_hum.h"
#include "localtime.h"
#include "networking.h"

*/

#endif // INC_INCLUDES_H_