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
            lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    {
        lv_obj_t *parent_obj = obj;
        {
            // imgWifiHome
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_wifi_home = obj;
            lv_obj_set_pos(obj, 10, 1);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_no_wifi);
            lv_obj_add_event_cb(obj, action_home_wifi_icon_click_cb, LV_EVENT_CLICKED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
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
            lv_obj_add_event_cb(obj, action_home_temp_panel_click_cb, LV_EVENT_CLICKED, (void *)0);
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
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
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
                    lv_label_set_text(obj, "Keg 1 Name");
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
                    lv_label_set_text(obj, "0");
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
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container2 = obj;
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
                    // pnlKegGraph2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph2 = obj;
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
                            // imgKeg2
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg2 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_add_event_cb(obj, action_keg2_home_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain2
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain2 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain2 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name2 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg 2 Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz2 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz2 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain2 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain2 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container3 = obj;
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
                    // pnlKegGraph3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph3 = obj;
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
                            // imgKeg3
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg3 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_add_event_cb(obj, action_keg3_home_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain3
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain3 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain3 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name3 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg 3 Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz3 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz3 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain3 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain3 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // pnlKegContainer4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_keg_container4 = obj;
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
                    // pnlKegGraph4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_keg_graph4 = obj;
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
                            // imgKeg4
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_keg4 = obj;
                            lv_obj_set_pos(obj, 5, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_keg_full);
                            lv_obj_add_event_cb(obj, action_keg4_home_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // barKegRemain4
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_keg_remain4 = obj;
                            lv_obj_set_pos(obj, -12, -35);
                            lv_obj_set_size(obj, 10, 140);
                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblKegPctRemain4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_keg_pct_remain4 = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "%");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // lblKegName4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_name4 = obj;
                    lv_obj_set_pos(obj, 8, 70);
                    lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Keg 4 Name");
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl16oz4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl16oz4 = obj;
                    lv_obj_set_pos(obj, 25, -53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl12oz4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl12oz4 = obj;
                    lv_obj_set_pos(obj, 25, -13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12 oz");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg16ozRemain4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg16oz_remain4 = obj;
                    lv_obj_set_pos(obj, -20, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lblKeg12ozRemain4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg12oz_remain4 = obj;
                    lv_obj_set_pos(obj, -20, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
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
            lv_obj_set_pos(obj, 0, -5);
            lv_obj_set_size(obj, 100, 45);
            lv_obj_add_event_cb(obj, action_keg_data_back_click_cb, LV_EVENT_CLICKED, (void *)0);
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
            // TabView1
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 40);
            objects.tab_view1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 40);
            lv_obj_add_event_cb(obj, action_tab_click_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
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
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_anim_duration(obj, 250, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_add_event_cb(obj, action_keg_name_click_cb, LV_EVENT_FOCUSED, (void *)0);
                    lv_obj_add_event_cb(obj, action_keg_name_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                    lv_obj_add_event_cb(obj, action_keg_name_click_cb, LV_EVENT_READY, (void *)0);
                    lv_obj_add_event_cb(obj, action_keg_name_click_cb, LV_EVENT_CANCEL, (void *)0);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_label_set_text(obj, "661 fl oz");
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
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
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
                    // lblKegStatus
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_keg_status = obj;
                    lv_obj_set_pos(obj, 0, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Scale: Connected-No Keg On Scale");
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // chkModifyKegdata
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.chk_modify_kegdata = obj;
                    lv_obj_set_pos(obj, 10, 20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Modify");
                    lv_obj_add_event_cb(obj, action_keg_check_modify_click_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ctrKegItems
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.ctr_keg_items = obj;
                    lv_obj_set_pos(obj, 0, 50);
                    lv_obj_set_size(obj, 480, 270);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
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
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                            add_style_panelstyle_noborder(obj);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 7);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Keg Type:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 70);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Empty Weight:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -300, 138);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Full Weight:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // kegTypeDropdown
                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                    objects.keg_type_dropdown = obj;
                                    lv_obj_set_pos(obj, 150, 0);
                                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                                    lv_dropdown_set_options(obj, "None\nHalf\nQuarter\nSixtel\n3 Gallon\n2.5 Gallon\n1.6 Gallon");
                                    lv_obj_add_event_cb(obj, action_keg_option_click_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);
                                }
                                {
                                    // txtWeightEmpty
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.txt_weight_empty = obj;
                                    lv_obj_set_pos(obj, 150, 63);
                                    lv_obj_set_size(obj, 70, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 5);
                                    lv_textarea_set_text(obj, "16");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_add_event_cb(obj, action_keg_empty_click_cb, LV_EVENT_FOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_empty_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_empty_click_cb, LV_EVENT_READY, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_empty_click_cb, LV_EVENT_CANCEL, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // txtWeightFull
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.txt_weight_full = obj;
                                    lv_obj_set_pos(obj, 150, 130);
                                    lv_obj_set_size(obj, 70, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 5);
                                    lv_textarea_set_text(obj, "80");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_add_event_cb(obj, action_keg_full_click_cb, LV_EVENT_FOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_full_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_full_click_cb, LV_EVENT_READY, (void *)0);
                                    lv_obj_add_event_cb(obj, action_keg_full_click_cb, LV_EVENT_CANCEL, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // btnKegdataReset
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.btn_kegdata_reset = obj;
                                    lv_obj_set_pos(obj, 0, -206);
                                    lv_obj_set_size(obj, 100, 45);
                                    lv_obj_add_event_cb(obj, action_keg_default_click_cb, LV_EVENT_CLICKED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Reset to Defaults");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // btnKegdataSave
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.btn_kegdata_save = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 45);
                                    lv_obj_add_event_cb(obj, action_keg_save_data_click_cb, LV_EVENT_CLICKED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Save");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // btnKegdataSetEmpty
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.btn_kegdata_set_empty = obj;
                                    lv_obj_set_pos(obj, 0, -137);
                                    lv_obj_set_size(obj, 100, 45);
                                    lv_obj_add_event_cb(obj, action_keg_set_empty_click_cb, LV_EVENT_CLICKED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Set Current as Empty");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // btnKegdataSetFull
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.btn_kegdata_set_full = obj;
                                    lv_obj_set_pos(obj, 0, -69);
                                    lv_obj_set_size(obj, 100, 45);
                                    lv_obj_add_event_cb(obj, action_keg_set_full_click_cb, LV_EVENT_CLICKED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Set Current as Full");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // btnKegdataRecalibrate
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.btn_kegdata_recalibrate = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 45);
                                    lv_obj_add_event_cb(obj, action_keg_calibrate_scale_click_cb, LV_EVENT_LONG_PRESSED, (void *)0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Recalibrate Scale");
                                            lv_obj_add_event_cb(obj, action_keg_calibrate_scale_click_cb, LV_EVENT_LONG_PRESSED, (void *)0);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
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
        {
            // kbdNumeric
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_numeric = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 360, 300);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // kbdNormal
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_normal = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(60));
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.kbd_normal, objects.txt_keg_name);
}

void tick_screen_scn_keg_data() {
}

void create_screen_scn_calibrate() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scn_calibrate = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_screenstyle(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            // pnlCalScreen
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_cal_screen = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 600, 400);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblScaleNum
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_scale_num = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Scale 1 Calibration");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // pnlCal2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_cal2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 500, 320);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // lblStep1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_step1 = obj;
                            lv_obj_set_pos(obj, 0, 12);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Step 1:  Remove  Everything from Scale");
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblStep2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_step2 = obj;
                            lv_obj_set_pos(obj, 0, 72);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Step 2: Place Known Weight on Scale");
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblStep3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_step3 = obj;
                            lv_obj_set_pos(obj, 0, 130);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Step 3: Enter the known weight in pounds:");
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // txtCalKnownWeight
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            objects.txt_cal_known_weight = obj;
                            lv_obj_set_pos(obj, 0, -107);
                            lv_obj_set_size(obj, 60, LV_SIZE_CONTENT);
                            lv_textarea_set_max_length(obj, 128);
                            lv_textarea_set_text(obj, "10");
                            lv_textarea_set_one_line(obj, false);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_add_event_cb(obj, action_cal_txt_click_cb, LV_EVENT_FOCUSED, (void *)0);
                            lv_obj_add_event_cb(obj, action_cal_txt_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                            lv_obj_add_event_cb(obj, action_cal_txt_click_cb, LV_EVENT_READY, (void *)0);
                            lv_obj_add_event_cb(obj, action_cal_txt_click_cb, LV_EVENT_CANCEL, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff939192), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblCalWeightLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_cal_weight_label = obj;
                            lv_obj_set_pos(obj, -210, -60);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Current Weight:");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblCalCurrWeight
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_cal_curr_weight = obj;
                            lv_obj_set_pos(obj, 270, -60);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "60.0 lbs");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // btnStep1
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_step1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 80, 40);
                            lv_obj_add_event_cb(obj, action_cal_step1_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Ok");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // btnStep2
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_step2 = obj;
                            lv_obj_set_pos(obj, 0, 60);
                            lv_obj_set_size(obj, 80, 40);
                            lv_obj_add_event_cb(obj, action_cal_step2_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Ok");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // btnStep3
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_step3 = obj;
                            lv_obj_set_pos(obj, 0, 150);
                            lv_obj_set_size(obj, 80, 40);
                            lv_obj_add_event_cb(obj, action_cal_step3_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Ok");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // btnCalCancel
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_cal_cancel = obj;
                            lv_obj_set_pos(obj, -80, -5);
                            lv_obj_set_size(obj, 80, 40);
                            lv_obj_add_event_cb(obj, action_cal_cancel_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Cancel");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // btnCalSave
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_cal_save = obj;
                            lv_obj_set_pos(obj, 70, -5);
                            lv_obj_set_size(obj, 80, 40);
                            lv_obj_add_event_cb(obj, action_cal_save_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Save");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_scn_calibrate() {
}

void create_screen_scn_wifi() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scn_wifi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_screenstyle(obj);
    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // pnlWifiMain
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_wifi_main = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 650, 440);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            add_style_panelstyle_withborder(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblWiFiTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_wi_fi_title = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WiFi Setup");
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // pnlWifiInfo
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.pnl_wifi_info = obj;
                    lv_obj_set_pos(obj, 0, -10);
                    lv_obj_set_size(obj, 520, 260);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // pnlWifiLabels
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.pnl_wifi_labels = obj;
                            lv_obj_set_pos(obj, -10, 0);
                            lv_obj_set_size(obj, 135, 180);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "SSID:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // lblPass
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_pass = obj;
                                    lv_obj_set_pos(obj, 0, 40);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Password:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // lblIP
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_ip = obj;
                                    lv_obj_set_pos(obj, 0, 80);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "IP Address:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // lblMDNS
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_mdns = obj;
                                    lv_obj_set_pos(obj, 0, 120);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "MDNS Hostname:");
                                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // pnlWifiTxt
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.pnl_wifi_txt = obj;
                            lv_obj_set_pos(obj, 125, 0);
                            lv_obj_set_size(obj, 200, 180);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // txtWifiSSID
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.txt_wifi_ssid = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 195, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_placeholder_text(obj, "SSID");
                                    lv_textarea_set_one_line(obj, true);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_add_event_cb(obj, action_wifi_ssid_click_cb, LV_EVENT_FOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_ssid_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_ssid_click_cb, LV_EVENT_READY, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_ssid_click_cb, LV_EVENT_CANCEL, (void *)0);
                                    lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // txtWifiPassword
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.txt_wifi_password = obj;
                                    lv_obj_set_pos(obj, 0, 40);
                                    lv_obj_set_size(obj, 195, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_text(obj, "myPass");
                                    lv_textarea_set_placeholder_text(obj, "Password");
                                    lv_textarea_set_one_line(obj, true);
                                    lv_textarea_set_password_mode(obj, true);
                                    lv_obj_add_event_cb(obj, action_wifi_pwd_click_cb, LV_EVENT_FOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_pwd_click_cb, LV_EVENT_DEFOCUSED, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_pwd_click_cb, LV_EVENT_READY, (void *)0);
                                    lv_obj_add_event_cb(obj, action_wifi_pwd_click_cb, LV_EVENT_CANCEL, (void *)0);
                                    lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // txtWifiIPAddr
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.txt_wifi_ip_addr = obj;
                                    lv_obj_set_pos(obj, 0, 80);
                                    lv_obj_set_size(obj, 195, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_placeholder_text(obj, "IP Address");
                                    lv_textarea_set_one_line(obj, true);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff414141), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_opa(obj, 96, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // lblMDNSName
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_mdns_name = obj;
                                    lv_obj_set_pos(obj, 5, 125);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "mykeezer.local");
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // pnlWifiRight
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.pnl_wifi_right = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 145, 150);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // chkVisible
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    objects.chk_visible = obj;
                                    lv_obj_set_pos(obj, 10, 50);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text(obj, "Visible");
                                    lv_obj_add_event_cb(obj, action_pass_visible_click_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
                                }
                                {
                                    // chkDHCP
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    objects.chk_dhcp = obj;
                                    lv_obj_set_pos(obj, 10, 90);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text(obj, "DHCP Enable");
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                }
                            }
                        }
                        {
                            // ledConnected
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.led_connected = obj;
                            lv_obj_set_pos(obj, -120, -17);
                            lv_obj_set_size(obj, 16, 16);
                            lv_led_set_color(obj, lv_color_hex(0xffff0000));
                            lv_led_set_brightness(obj, 224);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // lblConnected
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_connected = obj;
                            lv_obj_set_pos(obj, 355, -17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Not Connected");
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // btnWifiConnect
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_wifi_connect = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 100, 50);
                            lv_obj_add_event_cb(obj, action_wifi_connect_click_cb, LV_EVENT_CLICKED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Connect");
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // btnWifiBack
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_wifi_back = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, action_wifi_back_click_cb, LV_EVENT_CLICKED, (void *)0);
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
            }
        }
    }
}

void tick_screen_scn_wifi() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_scn_splash();
    create_screen_scn_home();
    create_screen_scn_keg_data();
    create_screen_scn_calibrate();
    create_screen_scn_wifi();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_scn_splash,
    tick_screen_scn_home,
    tick_screen_scn_keg_data,
    tick_screen_scn_calibrate,
    tick_screen_scn_wifi,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
