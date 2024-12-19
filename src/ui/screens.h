#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *scn_splash;
    lv_obj_t *scn_home;
    lv_obj_t *scn_keg_data;
    lv_obj_t *scn_calibrate;
    lv_obj_t *scn_wifi;
    lv_obj_t *lbl_loading;
    lv_obj_t *img_wifi_home;
    lv_obj_t *lbl_home_cur_time;
    lv_obj_t *pnl_temperature;
    lv_obj_t *lbl_keezer_cur_temp;
    lv_obj_t *lbl_deg_sym;
    lv_obj_t *lbl_temp_units;
    lv_obj_t *pnl_keg_container1;
    lv_obj_t *pnl_keg_graph1;
    lv_obj_t *img_keg1;
    lv_obj_t *bar_keg_remain1;
    lv_obj_t *lbl_keg_pct_remain1;
    lv_obj_t *lbl_keg_name1;
    lv_obj_t *lbl16oz1;
    lv_obj_t *lbl12oz1;
    lv_obj_t *lbl_keg16oz_remain1;
    lv_obj_t *lbl_keg12oz_remain1;
    lv_obj_t *pnl_keg_container2;
    lv_obj_t *pnl_keg_graph2;
    lv_obj_t *img_keg2;
    lv_obj_t *bar_keg_remain2;
    lv_obj_t *lbl_keg_pct_remain2;
    lv_obj_t *lbl_keg_name2;
    lv_obj_t *lbl16oz2;
    lv_obj_t *lbl12oz2;
    lv_obj_t *lbl_keg16oz_remain2;
    lv_obj_t *lbl_keg12oz_remain2;
    lv_obj_t *pnl_keg_container3;
    lv_obj_t *pnl_keg_graph3;
    lv_obj_t *img_keg3;
    lv_obj_t *bar_keg_remain3;
    lv_obj_t *lbl_keg_pct_remain3;
    lv_obj_t *lbl_keg_name3;
    lv_obj_t *lbl16oz3;
    lv_obj_t *lbl12oz3;
    lv_obj_t *lbl_keg16oz_remain3;
    lv_obj_t *lbl_keg12oz_remain3;
    lv_obj_t *pnl_keg_container4;
    lv_obj_t *pnl_keg_graph4;
    lv_obj_t *img_keg4;
    lv_obj_t *bar_keg_remain4;
    lv_obj_t *lbl_keg_pct_remain4;
    lv_obj_t *lbl_keg_name4;
    lv_obj_t *lbl16oz4;
    lv_obj_t *lbl12oz4;
    lv_obj_t *lbl_keg16oz_remain4;
    lv_obj_t *lbl_keg12oz_remain4;
    lv_obj_t *btn_kegdata_back;
    lv_obj_t *tab_view1;
    lv_obj_t *tab_page_1;
    lv_obj_t *tab_page_2;
    lv_obj_t *tab_page_3;
    lv_obj_t *tab_page_4;
    lv_obj_t *pnl_keg;
    lv_obj_t *img_keg_type;
    lv_obj_t *txt_keg_name;
    lv_obj_t *lbl_keg_capacity_name;
    lv_obj_t *lbl_keg_remain_name;
    lv_obj_t *lbl_keg_weight_name;
    lv_obj_t *lbl_keg_capacity_data;
    lv_obj_t *lbl_keg_remain_total_data;
    lv_obj_t *lbl_keg_weight_data;
    lv_obj_t *pnl_keg_data;
    lv_obj_t *lbl_keg_data_title;
    lv_obj_t *lbl_keg_status;
    lv_obj_t *chk_modify_kegdata;
    lv_obj_t *ctr_keg_items;
    lv_obj_t *pnl_keg_items;
    lv_obj_t *keg_type_dropdown;
    lv_obj_t *txt_weight_empty;
    lv_obj_t *txt_weight_full;
    lv_obj_t *btn_kegdata_reset;
    lv_obj_t *btn_kegdata_save;
    lv_obj_t *btn_kegdata_set_empty;
    lv_obj_t *btn_kegdata_set_full;
    lv_obj_t *btn_kegdata_recalibrate;
    lv_obj_t *kbd_numeric;
    lv_obj_t *kbd_normal;
    lv_obj_t *pnl_cal_screen;
    lv_obj_t *lbl_scale_num;
    lv_obj_t *pnl_cal2;
    lv_obj_t *lbl_step1;
    lv_obj_t *lbl_step2;
    lv_obj_t *lbl_step3;
    lv_obj_t *txt_cal_known_weight;
    lv_obj_t *lbl_cal_weight_label;
    lv_obj_t *lbl_cal_curr_weight;
    lv_obj_t *btn_step1;
    lv_obj_t *btn_step2;
    lv_obj_t *btn_step3;
    lv_obj_t *btn_cal_cancel;
    lv_obj_t *btn_cal_save;
    lv_obj_t *pnl_wifi_main;
    lv_obj_t *lbl_wi_fi_title;
    lv_obj_t *pnl_wifi_info;
    lv_obj_t *pnl_wifi_labels;
    lv_obj_t *lbl_pass;
    lv_obj_t *lbl_ip;
    lv_obj_t *lbl_mdns;
    lv_obj_t *pnl_wifi_txt;
    lv_obj_t *txt_wifi_ssid;
    lv_obj_t *txt_wifi_password;
    lv_obj_t *txt_wifi_ip_addr;
    lv_obj_t *lbl_mdns_name;
    lv_obj_t *pnl_wifi_right;
    lv_obj_t *chk_visible;
    lv_obj_t *chk_dhcp;
    lv_obj_t *led_connected;
    lv_obj_t *lbl_connected;
    lv_obj_t *btn_wifi_connect;
    lv_obj_t *btn_wifi_back;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SCN_SPLASH = 1,
    SCREEN_ID_SCN_HOME = 2,
    SCREEN_ID_SCN_KEG_DATA = 3,
    SCREEN_ID_SCN_CALIBRATE = 4,
    SCREEN_ID_SCN_WIFI = 5,
};

void create_screen_scn_splash();
void tick_screen_scn_splash();

void create_screen_scn_home();
void tick_screen_scn_home();

void create_screen_scn_keg_data();
void tick_screen_scn_keg_data();

void create_screen_scn_calibrate();
void tick_screen_scn_calibrate();

void create_screen_scn_wifi();
void tick_screen_scn_wifi();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/