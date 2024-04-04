// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: BTHome v2_xG24_xG27_sensors_with_LVGL

#include "../ui.h"

void ui_BootScreen_screen_init(void)
{
    ui_BootScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BootScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BootScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_imgsilabsbig = lv_img_create(ui_BootScreen);
    lv_img_set_src(ui_imgsilabsbig, &ui_img_1597985048);
    lv_obj_set_width(ui_imgsilabsbig, LV_SIZE_CONTENT);   /// 200
    lv_obj_set_height(ui_imgsilabsbig, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(ui_imgsilabsbig, -2);
    lv_obj_set_y(ui_imgsilabsbig, -10);
    lv_obj_set_align(ui_imgsilabsbig, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgsilabsbig, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgsilabsbig, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
