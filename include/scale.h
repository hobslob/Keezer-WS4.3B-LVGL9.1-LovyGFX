#ifndef INC_SCALE_H_
#define INC_SCALE_H_

//NAU7802 myScales[4]; //Create 4 instances of the NAU7802 class


// Public Function Prototypes
void setup_scales ( void );
void Calibrate_Scale ( uint8_t scalenum );
void Write_Calibration_Settings_to_Scale ( uint8_t scalenum );
float Get_Instantaneous_Weight ( uint8_t keg_num );
void Get_Keg_Weight ( uint8_t keg_num );
void Calculate_New_Zero_Offset(uint8_t scalenum);
void Calculate_New_Cal_Factor(uint8_t scalenum, float weightOnScale);
void ReCalibrate_Scale_AFE (uint8_t scalenum);
void Read_Calibration_Settings_from_Scale (uint8_t scalenum);


#endif /* INC_SCALE_H_ */