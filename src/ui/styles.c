#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "screens.h"

//
// Style: screenstyle
//

void init_style_screenstyle_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_screenstyle_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_screenstyle_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_screenstyle(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_screenstyle_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_screenstyle(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_screenstyle_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: panelstyle-noborder
//

void init_style_panelstyle_noborder_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff14181d));
};

lv_style_t *get_style_panelstyle_noborder_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panelstyle_noborder_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panelstyle_noborder(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_panelstyle_noborder_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panelstyle_noborder(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_panelstyle_noborder_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: panelstyle-withborder
//

void init_style_panelstyle_withborder_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff14181d));
    lv_style_set_border_color(style, lv_color_hex(0xff414141));
    lv_style_set_border_width(style, 1);
};

lv_style_t *get_style_panelstyle_withborder_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panelstyle_withborder_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panelstyle_withborder(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_panelstyle_withborder_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panelstyle_withborder(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_panelstyle_withborder_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_screenstyle,
        add_style_panelstyle_noborder,
        add_style_panelstyle_withborder,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_screenstyle,
        remove_style_panelstyle_noborder,
        remove_style_panelstyle_withborder,
    };
    remove_style_funcs[styleIndex](obj);
}

