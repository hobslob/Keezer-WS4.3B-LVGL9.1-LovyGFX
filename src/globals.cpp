#include "includes.h"


ScaleInfo ScaleData[4];
KeezerInfo MyKeezer;
NewScaleInfo NewScaleData[4];
KegInfo KegData[4];

unsigned long ota_progress_millis = 0;
bool hardware_initialized;


JsonDocument readings;  // Json Variable to Hold Sensor Readings
JsonDocument kegsettings;   // Json Variable to Hold Sensor Readings

float tempCalibrationFactor;
int32_t tempZeroOffset;

bool firmware_update_inprogress = false;
bool firmware_update_start = false;
bool firmware_update_done = false;

// none, half, quarter, sixtel, 3gal, 2.5gal, 1.6gal
float keg_capacities [7]    = {0, 1984, 992, 661, 384, 320, 128 };
float keg_full_weights [7]  = {0, 160, 87, 58, 33.5, 27.5, 18.5 };
float keg_empty_weights [7] = {0, 30, 22, 16.5, 8.5, 7, 5 };
