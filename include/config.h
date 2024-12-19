
#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "includes.h"

/*
// Pin Defines
// I2C1 on UM Feather S3
#define UM_SDA1 8
#define UM_SCL1 9

// SPI on UM Feather S3
#define UM_MOSI 35
#define UM_MISO 37
#define UM_SCk  36

// The 3.5" display also uses hardware SPI, plus #9 & #10 (Arduino) or 1 & 3 UM FeatherS3
#define TFT_CS         1
#define TFT_RST        -1
#define TFT_DC         3
*/

#define MDNS_HOSTNAME "mykeezer"

#define SCALE1          0
#define SCALE2          1
#define SCALE3          2
#define SCALE4          3

#define KEG1            0
#define KEG2            1
#define KEG3            2
#define KEG4            3

#define KEGTYPE_FULL        0
#define KEGTYPE_SIXTEL      1
#define KEGTYPE_3GAL        2
#define KEGTYPE_2P5GAL      3
#define KEGTYPE_2GAL        4
#define KEGTYPE_1GAL        5

#define KEGTYPE_NITRO       KEGTYPE_2GAL

#define KEGCONTENTS_BEER  0
#define KEGCONTENTS_WATER 1

#define PCA9548_7BIT_ADDR 0x70
#define PCA9548_PORTS_OFF 0x00
#define PCA9548_PORT0     0x01
#define PCA9548_PORT1     0x02
#define PCA9548_PORT2     0x04
#define PCA9548_PORT3     0x08
#define PCA9548_PORT4     0x10
#define PCA9548_PORT5     0x20
#define PCA9548_PORT6     0x40
#define PCA9548_PORT7     0x80

#define KEG_DETECT_WEIGHT_THRESHOLD 1.00f   // 1 pound
#define SIXTEL_CAPACITY_OZ  661.0f
#define SIXTEL_EMPTY_WEIGHT 16.0f
#define SIXTEL_FULL_WEIGHT  58.0f

#define LIPO_MAXV           4.2f
#define LIPO_MINV           3.3f  // Approx

#define BEER_LBS_PER_OZ     0.065f
#define BEER_OZ_PER_LB      15.384f


#define NUM_WEIGHT_SAMPLES 8

#define TEMPERATURE_UNITS_C  0
#define TEMPERATURE_UNITS_F   1



typedef struct
{
    uint8_t       KegType;              // Type of Keg: Sixtel or Nitro
    uint8_t       I2C_Mux_Port;         // Port # of PCA9548 the NAU7208 is connected to: 0-8
    bool          isPresent;            // Is it connected
    float         CalibrationFactor;    // Value used to convert the load cell reading to lbs or kg
    int32_t       ZeroOffset;           // Zero value that is found when scale is tared
    float         EmptyWeight;          // Weight Value of Keg when Empty
    float         FullWeight;           // Weight Value of Keg when Full
    float         CurrentWeight;        // Current Weight of Keg
    float         PercentFull;          // Percentage left in Keg
    float         remainingTotalOz;     // Number of 16 ounce "Pints" left in Keg
    float         Remaining16oz;        // Number of 16 ounce "Pints" left in Keg
    float         Remaining12oz;        // Number of 12 ounce "Cans" left in Keg
    String        KegName;              // Name for the Scale, e.g. "Keg 1"
    uint8_t       ContentType;          // Content Type of the Keg: Beer or Water. Used to compensate for different weights of Beer & water per oz.
    String        ContentName;          // Name of the contents, e.g. "Water"
    
} ScaleInfo;


typedef struct
{
    bool          isTempProbeInstalled;       // Is it connected
    bool          isTempControllerInstalled;  // Is it connected
    bool          isWiFiConnected;            // Is it connected
    bool          isScaleInstalled[4];        // Is it connected
    bool          isScale1Installed;          // Is it connected
    bool          isScale2Installed;          // Is it connected
    bool          isScale3Installed;          // Is it connected
    bool          isScale4Installed;          // Is it connected
    bool          isBatteryCharging;          // Battery charging state
    uint8_t       BatteryPercentage;          // Battery Charge Percentage
    uint8_t       PowerSource;                // Power source: Battery, USB
    uint8_t       Temp_Controller_State;      // State of Temperature Controller: ON, OFF
    uint8_t       Temp_Display_Units;         // Display C(0) or F(1)
    float         TemperatureDegF;            // Temperature reading from SHT sensor
    float         TemperatureDegC;            // Temperature reading from SHT sensor
    float         Humidity;                   // Humidity reading from SHT sensor
    String        KeezerName;                 // Name of the Keezer, e.g. "Jims Keezer"
    String        WiFiSSID;                   // WiFi SSID
    String        WiFiPWD;                    // WiFi Password
    
} KeezerInfo;


typedef struct
{
    bool          isPresent;            // Is it connected
    uint8_t       I2C_Mux_Port;         // Port # of PCA9548 the NAU7208 is connected to: 0-8
    float         CalibrationFactor;    // Value used to convert the load cell reading to lbs or kg
    int32_t       ZeroOffset;           // Zero value that is found when scale is tared
    float         CurrentWeight;        // Current Weight of Keg
    String        ScaleName;            // Name of the scale, e.g. "Scale1"
    
} NewScaleInfo;



typedef struct
{
    bool          isPresent;            // Is it connected
    uint8_t       KegType;              // Type of Keg: Sixtel or Nitro
    float         EmptyWeight;          // Weight Value of Keg when Empty
    float         FullWeight;           // Weight Value of Keg when Full
    float         CurrentWeight;        // Current Weight of Keg
    float         PercentFull;          // Percentage left in Keg
    float         remainingTotalOz;     // Number of 16 ounce "Pints" left in Keg
    float         Remaining16oz;        // Number of 16 ounce "Pints" left in Keg
    float         Remaining12oz;        // Number of 12 ounce "Cans" left in Keg
    uint8_t       sample_index;         // Running sample counter to calculate average
    float         sampledata[NUM_WEIGHT_SAMPLES];  // Array of raw weight measurements
    uint8_t       ContentType;          // Content Type of the Keg: Beer or Water. Used to compensate for different weights of Beer & water per oz.
    String        KegName;              // Name for the Scale, e.g. "Keg 1"
    String        ContentName;          // Name of the contents, e.g. "Water"
    
} KegInfo;


// Public Funciton Prototypes
// void WiFi_Setup ( void );
// void MDNS_Setup ( void );



#endif /* INC_CONFIG_H_ */