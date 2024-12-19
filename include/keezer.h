#ifndef INC_KEEZER_H_
#define INC_KEEZER_H_


// Public Function Prototypes
void init_keezer (void);

void Select_I2C_Mux_Port(uint8_t port_select);
String getSensorReadingsJSON();

void Calculate_Remainig_Content (KegInfo *keg);
void Detect_Kegs ( void );

void Save_Scale_Settings_To_NV_Storage ( uint8_t scalenum );
void Read_Settings_From_NV_Storage ( void );
void Save_Kegname_To_NVStorage ( uint8_t kegnum );
void Save_WiFi_To_NVStorage ( void );
void update_all_kegnames ( void );

void Update_MainScreen_Kegdata (uint8_t kegnum);
void Update_pnl_keg_Info ( void );
void Update_pnl_keg_capacity ( uint8_t kegnum );


// void kegdata_canvas_init ( void );
// void Populate_Kegdata_Canvas (uint8_t kegnum);
// void Display_Kegdata_Canvas ( void );



#endif /* INC_KEEZER_H_ */