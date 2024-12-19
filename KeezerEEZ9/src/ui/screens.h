#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *scn_splash;
    lv_obj_t *scn_home;
    lv_obj_t *scn_keg_data;
    lv_obj_t *bar_keg_remain1;
    lv_obj_t *bar_keg_remain1_1;
    lv_obj_t *bar_keg_remain1_2;
    lv_obj_t *bar_keg_remain1_3;
    lv_obj_t *btn_kegdata_back;
    lv_obj_t *chk_modify_kegdata;
    lv_obj_t *img_keg_type;
    lv_obj_t *img_keg1;
    lv_obj_t *img_keg1_1;
    lv_obj_t *img_keg1_2;
    lv_obj_t *img_keg1_3;
    lv_obj_t *img_wifi_home;
    lv_obj_t *kbd_numeric;
    lv_obj_t *lbl_deg_sym;
    lv_obj_t *lbl_home_cur_time;
    lv_obj_t *lbl_keezer_cur_temp;
    lv_obj_t *lbl_keg_capacity_data;
    lv_obj_t *lbl_keg_capacity_name;
    lv_obj_t *lbl_keg_data_title;
    lv_obj_t *lbl_keg_name1;
    lv_obj_t *lbl_keg_name1_1;
    lv_obj_t *lbl_keg_name1_2;
    lv_obj_t *lbl_keg_name1_3;
    lv_obj_t *lbl_keg_pct_remain1;
    lv_obj_t *lbl_keg_pct_remain1_1;
    lv_obj_t *lbl_keg_pct_remain1_2;
    lv_obj_t *lbl_keg_pct_remain1_3;
    lv_obj_t *lbl_keg_remain_name;
    lv_obj_t *lbl_keg_remain_total_data;
    lv_obj_t *lbl_keg_status;
    lv_obj_t *lbl_keg_weight_data;
    lv_obj_t *lbl_keg_weight_name;
    lv_obj_t *lbl_keg12oz_remain1;
    lv_obj_t *lbl_keg12oz_remain1_1;
    lv_obj_t *lbl_keg12oz_remain1_2;
    lv_obj_t *lbl_keg12oz_remain1_3;
    lv_obj_t *lbl_keg16oz_remain1;
    lv_obj_t *lbl_keg16oz_remain1_1;
    lv_obj_t *lbl_keg16oz_remain1_2;
    lv_obj_t *lbl_keg16oz_remain1_3;
    lv_obj_t *lbl_loading;
    lv_obj_t *lbl_temp_units;
    lv_obj_t *lbl12oz1;
    lv_obj_t *lbl12oz1_1;
    lv_obj_t *lbl12oz1_2;
    lv_obj_t *lbl12oz1_3;
    lv_obj_t *lbl16oz1;
    lv_obj_t *lbl16oz1_1;
    lv_obj_t *lbl16oz1_2;
    lv_obj_t *lbl16oz1_3;
    lv_obj_t *pnl_keg;
    lv_obj_t *pnl_keg_container1;
    lv_obj_t *pnl_keg_container1_1;
    lv_obj_t *pnl_keg_container1_2;
    lv_obj_t *pnl_keg_container1_3;
    lv_obj_t *pnl_keg_data;
    lv_obj_t *pnl_keg_graph1;
    lv_obj_t *pnl_keg_graph1_1;
    lv_obj_t *pnl_keg_graph1_2;
    lv_obj_t *pnl_keg_graph1_3;
    lv_obj_t *pnl_keg_items;
    lv_obj_t *pnl_temperature;
    lv_obj_t *tab_page_1;
    lv_obj_t *tab_page_2;
    lv_obj_t *tab_page_3;
    lv_obj_t *tab_page_4;
    lv_obj_t *tab_view1;
    lv_obj_t *txt_keg_name;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SCN_SPLASH = 1,
    SCREEN_ID_SCN_HOME = 2,
    SCREEN_ID_SCN_KEG_DATA = 3,
};

void create_screen_scn_splash();
void tick_screen_scn_splash();

void create_screen_scn_home();
void tick_screen_scn_home();

void create_screen_scn_keg_data();
void tick_screen_scn_keg_data();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/