#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

//#include "includes.h"



extern ScaleInfo ScaleData[];
extern KeezerInfo MyKeezer;
extern NewScaleInfo NewScaleData[];
extern KegInfo KegData[];

extern unsigned long ota_progress_millis;
extern bool hardware_initialized;


extern JsonDocument readings;
extern JsonDocument kegsettings;

extern float tempCalibrationFactor;
extern int32_t tempZeroOffset;

extern bool firmware_update_inprogress;
extern bool firmware_update_start;
extern bool firmware_update_done;

extern float keg_capacities[];
extern float keg_full_weights[];
extern float keg_empty_weights[];

#endif // INC_GLOBALS_H_