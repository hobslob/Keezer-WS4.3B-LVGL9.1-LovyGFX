#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_scn_splash() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scn_splash = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(obj, &img_bobo, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lblLoading
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_loading = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Loading...");
            lv_obj_add_event_cb(obj, action_keg1_home_click_cb, LV_EVENT_CLICKED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff070707), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 2192, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scn_splash() {
}

void create_screen_scn_home() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scn_home = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_screenstyle(obj);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // imgWifiHome
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_wifi_home = obj;
            lv_obj_set_pos(obj, 10, 1);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_no_wifi);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lblHomeCurTime
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_home_cur_time = obj;
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "No Connection to NTP Server");
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // pnlTemperature
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_temperature = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblKeezerCurTemp
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keezer_cur_temp = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "99.9");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblDegSym
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_deg_sym = obj;
                    lv_obj_set_pos(obj, -13, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "°");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblTempUnits
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_temp_units = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "F");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container1 = obj;
            lv_obj_set_pos(obj, 10, -25);
            lv_obj_set_size(obj, 180, 370);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // pnlKegGraph1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 170, 220);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // imgKeg1
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg1 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_add_event_cb(obj, action_keg1_home_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain1
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain1 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain1 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name1 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz1 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz1 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain1 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "45");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain1 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "55");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer1_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container1_1 = obj;
            lv_obj_set_pos(obj, 210, -25);
            lv_obj_set_size(obj, 180, 370);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // pnlKegGraph1_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph1_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 170, 220);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // imgKeg1_1
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg1_1 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_add_event_cb(obj, action_keg2_home_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain1_1
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain1_1 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain1_1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain1_1 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName1_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name1_1 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz1_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz1_1 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz1_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz1_1 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain1_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain1_1 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "45");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain1_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain1_1 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "55");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer1_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container1_2 = obj;
            lv_obj_set_pos(obj, 410, -25);
            lv_obj_set_size(obj, 180, 370);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // pnlKegGraph1_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph1_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 170, 220);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // imgKeg1_2
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg1_2 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain1_2
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain1_2 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain1_2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain1_2 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName1_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name1_2 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz1_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz1_2 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz1_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz1_2 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain1_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain1_2 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "45");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain1_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain1_2 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "55");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer1_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container1_3 = obj;
            lv_obj_set_pos(obj, 610, -25);
            lv_obj_set_size(obj, 180, 370);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // pnlKegGraph1_3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph1_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 170, 220);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101818), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // imgKeg1_3
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg1_3 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain1_3
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain1_3 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain1_3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain1_3 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName1_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name1_3 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz1_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz1_3 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz1_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz1_3 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain1_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain1_3 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "45");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain1_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain1_3 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "55");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_scn_home() {
}

void create_screen_scn_keg_data() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scn_keg_data = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_screenstyle(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnKegdataBack
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_kegdata_back = obj;
            lv_obj_set_pos(obj, 0, -2);
            lv_obj_set_size(obj, 100, 45);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // lblKegStatus
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_keg_status = obj;
            lv_obj_set_pos(obj, -2, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Scale: Connected-No Keg On Scale");
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // kbdNumeric
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_numeric = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 360, 300);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // TabView1
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 40);
            objects.tab_view1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 40);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_get_tab_bar(parent_obj);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Tab Page 1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Keg 1");
                            objects.tab_page_1 = obj;
                        }
                        {
                            // Tab Page 2
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Keg 2");
                            objects.tab_page_2 = obj;
                        }
                        {
                            // Tab Page 3
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Keg 3");
                            objects.tab_page_3 = obj;
                        }
                        {
                            // Tab Page 4
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Keg 4");
                            objects.tab_page_4 = obj;
                        }
                    }
                }
            }
        }
        {
            // pnlKeg
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg = obj;
            lv_obj_set_pos(obj, 20, 60);
            lv_obj_set_size(obj, 260, 360);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // imgKegType
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.img_keg_type = obj;
                    lv_obj_set_pos(obj, 0, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_keg_full);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txtKegName
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_keg_name = obj;
                    lv_obj_set_pos(obj, 10, 68);
                    lv_obj_set_size(obj, 240, LV_SIZE_CONTENT);
                    lv_textarea_set_max_length(obj, 48);
                    lv_textarea_set_text(obj, "Keg Name");
                    lv_textarea_set_placeholder_text(obj, "Keg Name");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegCapacityName
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_capacity_name = obj;
                    lv_obj_set_pos(obj, -135, -55);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Capacity:");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegRemainName
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_remain_name = obj;
                    lv_obj_set_pos(obj, -135, -30);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Remaining:");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegWeightName
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_weight_name = obj;
                    lv_obj_set_pos(obj, -135, -5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Weight:");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegCapacityData
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_capacity_data = obj;
                    lv_obj_set_pos(obj, 135, -55);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "660 fl oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegRemainTotalData
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_remain_total_data = obj;
                    lv_obj_set_pos(obj, 135, -30);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "660 fl oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKegWeightData
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_weight_data = obj;
                    lv_obj_set_pos(obj, 135, -5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "100.0 lbs");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegData
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_data = obj;
            lv_obj_set_pos(obj, -20, 60);
            lv_obj_set_size(obj, 480, 360);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblKegDataTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_data_title = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg 1 Settings");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // chkModifyKegdata
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.chk_modify_kegdata = obj;
                    lv_obj_set_pos(obj, 10, 20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Modify");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 50);
                    lv_obj_set_size(obj, 480, 280);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_snap_x(obj, LV_DIR_NONE);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // pnlKegItems
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.pnl_keg_items = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 480, 280);
                            add_style_panelstyle_noborder(obj);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Keg Type:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 40);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Empty Weight:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 80);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Full Weight:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                    lv_obj_set_pos(obj, 150, -5);
                                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                                    lv_dropdown_set_options(obj, "None\nFull\nSixtel\n3 Gallon\n2.5 Gallon\n1 Gallon");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    lv_obj_set_pos(obj, 150, 34);
                                    lv_obj_set_size(obj, 50, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 3);
                                    lv_textarea_set_text(obj, "16");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    lv_obj_set_pos(obj, 150, 74);
                                    lv_obj_set_size(obj, 50, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 3);
                                    lv_textarea_set_text(obj, "80");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_scn_keg_data() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_scn_splash();
    create_screen_scn_home();
    create_screen_scn_keg_data();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_scn_splash,
    tick_screen_scn_home,
    tick_screen_scn_keg_data,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
