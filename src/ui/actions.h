#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_keg1_home_click_cb(lv_event_t * e);
extern void action_keg2_home_click_cb(lv_event_t * e);
extern void action_keg3_home_click_cb(lv_event_t * e);
extern void action_keg4_home_click_cb(lv_event_t * e);
extern void action_pass_visible_click_cb(lv_event_t * e);
extern void action_wifi_connect_click_cb(lv_event_t * e);
extern void action_wifi_back_click_cb(lv_event_t * e);
extern void action_wifi_ssid_click_cb(lv_event_t * e);
extern void action_wifi_pwd_click_cb(lv_event_t * e);
extern void action_tab1_click_cb(lv_event_t * e);
extern void action_tab2_click_cb(lv_event_t * e);
extern void action_tab3_click_cb(lv_event_t * e);
extern void action_tab4_click_cb(lv_event_t * e);
extern void action_keg_name_click_cb(lv_event_t * e);

extern void action_keg_check_modify_click_cb(lv_event_t * e);
extern void set_kegdata_modify_clickable_state ( lv_state_t flag_state );


extern void action_keg_option_click_cb(lv_event_t * e);
extern void action_keg_empty_click_cb(lv_event_t * e);
extern void action_keg_full_click_cb(lv_event_t * e);
extern void action_keg_default_click_cb(lv_event_t * e);
extern void action_keg_set_empty_click_cb(lv_event_t * e);
extern void action_keg_set_full_click_cb(lv_event_t * e);
extern void action_keg_save_data_click_cb(lv_event_t * e);
extern void action_keg_calibrate_scale_click_cb(lv_event_t * e);
extern void action_keg_data_back_click_cb(lv_event_t * e);
extern void action_home_wifi_icon_click_cb(lv_event_t * e);
extern void action_home_temp_panel_click_cb(lv_event_t * e);
extern void action_cal_step1_click_cb(lv_event_t * e);
extern void action_cal_step2_click_cb(lv_event_t * e);
extern void action_cal_step3_click_cb(lv_event_t * e);
extern void action_cal_txt_click_cb(lv_event_t * e);
extern void action_cal_cancel_click_cb(lv_event_t * e);
extern void action_cal_save_click_cb(lv_event_t * e);
extern void action_tab_click_cb(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/