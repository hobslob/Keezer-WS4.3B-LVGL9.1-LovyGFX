#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: screenstyle
lv_style_t *get_style_screenstyle_MAIN_DEFAULT();
void add_style_screenstyle(lv_obj_t *obj);
void remove_style_screenstyle(lv_obj_t *obj);

// Style: panelstyle-noborder
lv_style_t *get_style_panelstyle_noborder_MAIN_DEFAULT();
void add_style_panelstyle_noborder(lv_obj_t *obj);
void remove_style_panelstyle_noborder(lv_obj_t *obj);

// Style: panelstyle-withborder
lv_style_t *get_style_panelstyle_withborder_MAIN_DEFAULT();
void add_style_panelstyle_withborder(lv_obj_t *obj);
void remove_style_panelstyle_withborder(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/