#ifndef __ANIMATIONS_H__
#define __ANIMATIONS_H__

#include <lvgl.h>


#ifdef __cplusplus
extern "C" {
#endif

void anim_x_cb(void * var, int32_t v);
void anim_y_cb(void * var, int32_t v);

void animate_obj_Up200pix(lv_obj_t * TargetObject, int delay);
void animate_obj_Down200pix(lv_obj_t * TargetObject, int delay);
void animate_obj_Right50pix(lv_obj_t * TargetObject, int delay);
void animate_obj_Left50pix(lv_obj_t * TargetObject, int delay);


#ifdef __cplusplus
}
#endif

#endif // __ANIMATIONS_H__