// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: BTHome v2_xG24_xG27_sensors_with_LVGL

#include "../ui.h"

void ui_ApplicationScreen_screen_init(void)
{
    ui_ApplicationScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ApplicationScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ApplicationScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ApplicationScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar1 = lv_bar_create(ui_ApplicationScreen);
    lv_bar_set_value(ui_Bar1, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_Bar1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar1, 320);
    lv_obj_set_height(ui_Bar1, 1);
    lv_obj_set_x(ui_Bar1, -1);
    lv_obj_set_y(ui_Bar1, -80);
    lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Bar1, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_imgbthome = lv_img_create(ui_ApplicationScreen);
    lv_img_set_src(ui_imgbthome, &ui_img_25_png);
    lv_obj_set_width(ui_imgbthome, LV_SIZE_CONTENT);   /// 84
    lv_obj_set_height(ui_imgbthome, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_imgbthome, -42);
    lv_obj_set_y(ui_imgbthome, 9);
    lv_obj_set_align(ui_imgbthome, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_imgbthome, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgbthome, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_imglvgl = lv_img_create(ui_ApplicationScreen);
    lv_img_set_src(ui_imglvgl, &ui_img_25_78_png);
    lv_obj_set_width(ui_imglvgl, LV_SIZE_CONTENT);   /// 78
    lv_obj_set_height(ui_imglvgl, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_imglvgl, 120);
    lv_obj_set_y(ui_imglvgl, -100);
    lv_obj_set_align(ui_imglvgl, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imglvgl, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imglvgl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_imgsilabs = lv_img_create(ui_ApplicationScreen);
    lv_img_set_src(ui_imgsilabs, &ui_img_30_60_png);
    lv_obj_set_width(ui_imgsilabs, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_imgsilabs, LV_SIZE_CONTENT);    /// 30
    lv_obj_set_x(ui_imgsilabs, -127);
    lv_obj_set_y(ui_imgsilabs, -100);
    lv_obj_set_align(ui_imgsilabs, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgsilabs, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgsilabs, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_imgzephyr = lv_img_create(ui_ApplicationScreen);
    lv_img_set_src(ui_imgzephyr, &ui_img_35_67_png);
    lv_obj_set_width(ui_imgzephyr, LV_SIZE_CONTENT);   /// 67
    lv_obj_set_height(ui_imgzephyr, LV_SIZE_CONTENT);    /// 35
    lv_obj_set_x(ui_imgzephyr, 39);
    lv_obj_set_y(ui_imgzephyr, -100);
    lv_obj_set_align(ui_imgzephyr, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgzephyr, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgzephyr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_labeltextSi7021 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labeltextSi7021, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labeltextSi7021, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labeltextSi7021, -100);
    lv_obj_set_y(ui_labeltextSi7021, -58);
    lv_obj_set_align(ui_labeltextSi7021, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labeltextSi7021, "Si7021 RHT Sensor");
    lv_obj_set_style_text_font(ui_labeltextSi7021, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelTempValue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelTempValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelTempValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelTempValue, 69);
    lv_obj_set_y(ui_labelTempValue, -58);
    lv_obj_set_align(ui_labelTempValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelTempValue, "N/A");
    lv_obj_clear_flag(ui_labelTempValue, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelTempValue, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelTempValue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelcelciousSymbol = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelcelciousSymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelcelciousSymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelcelciousSymbol, 94);
    lv_obj_set_y(ui_labelcelciousSymbol, -58);
    lv_obj_set_align(ui_labelcelciousSymbol, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelcelciousSymbol, "°C");
    lv_obj_set_style_text_font(ui_labelcelciousSymbol, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelhumidityValue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelhumidityValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelhumidityValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelhumidityValue, 124);
    lv_obj_set_y(ui_labelhumidityValue, -58);
    lv_obj_set_align(ui_labelhumidityValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelhumidityValue, "N/A");
    lv_obj_set_style_text_font(ui_labelhumidityValue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelhumiditypercent = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelhumiditypercent, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelhumiditypercent, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelhumiditypercent, 147);
    lv_obj_set_y(ui_labelhumiditypercent, -58);
    lv_obj_set_align(ui_labelhumiditypercent, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelhumiditypercent, "%");
    lv_obj_set_style_text_font(ui_labelhumiditypercent, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelVEML6035 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelVEML6035, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelVEML6035, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelVEML6035, -57);
    lv_obj_set_y(ui_labelVEML6035, -33);
    lv_obj_set_align(ui_labelVEML6035, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelVEML6035, "VEML6035 Ambient Light Sensor");
    lv_obj_set_style_text_font(ui_labelVEML6035, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelSI7210Hall = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelSI7210Hall, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelSI7210Hall, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelSI7210Hall, -83);
    lv_obj_set_y(ui_labelSI7210Hall, -8);
    lv_obj_set_align(ui_labelSI7210Hall, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelSI7210Hall, "Si7210 Hall Effect Sensor");
    lv_obj_set_style_text_font(ui_labelSI7210Hall, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelBMP384Barometric = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelBMP384Barometric, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelBMP384Barometric, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelBMP384Barometric, -40);
    lv_obj_set_y(ui_labelBMP384Barometric, 20);
    lv_obj_set_align(ui_labelBMP384Barometric, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelBMP384Barometric, "BMP384 Barometric Pressuare Sensor");
    lv_obj_set_style_text_font(ui_labelBMP384Barometric, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar2 = lv_bar_create(ui_ApplicationScreen);
    lv_bar_set_value(ui_Bar2, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_Bar2, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar2, 320);
    lv_obj_set_height(ui_Bar2, 1);
    lv_obj_set_x(ui_Bar2, 0);
    lv_obj_set_y(ui_Bar2, 57);
    lv_obj_set_align(ui_Bar2, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Bar2, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_labelICM20689 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelICM20689, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelICM20689, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelICM20689, -58);
    lv_obj_set_y(ui_labelICM20689, 45);
    lv_obj_set_align(ui_labelICM20689, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelICM20689, "ICM-20689 6-Axis Inertial Sensor");
    lv_obj_set_style_text_font(ui_labelICM20689, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelVEMLAmbientLightValue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelVEMLAmbientLightValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelVEMLAmbientLightValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelVEMLAmbientLightValue, 118);
    lv_obj_set_y(ui_labelVEMLAmbientLightValue, -30);
    lv_obj_set_align(ui_labelVEMLAmbientLightValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelVEMLAmbientLightValue, "N/A");
    lv_obj_set_style_text_font(ui_labelVEMLAmbientLightValue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labellxsymbol = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labellxsymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labellxsymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labellxsymbol, 149);
    lv_obj_set_y(ui_labellxsymbol, -30);
    lv_obj_set_align(ui_labellxsymbol, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labellxsymbol, "lx");
    lv_obj_set_style_text_font(ui_labellxsymbol, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelsi7210HallEffectValue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelsi7210HallEffectValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelsi7210HallEffectValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelsi7210HallEffectValue, 117);
    lv_obj_set_y(ui_labelsi7210HallEffectValue, -7);
    lv_obj_set_align(ui_labelsi7210HallEffectValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelsi7210HallEffectValue, "N/A");
    lv_obj_set_style_text_font(ui_labelsi7210HallEffectValue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelmTSymbol = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelmTSymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelmTSymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelmTSymbol, 145);
    lv_obj_set_y(ui_labelmTSymbol, -7);
    lv_obj_set_align(ui_labelmTSymbol, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelmTSymbol, "mT");
    lv_obj_set_style_text_font(ui_labelmTSymbol, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelBMP384Value = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelBMP384Value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelBMP384Value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelBMP384Value, 102);
    lv_obj_set_y(ui_labelBMP384Value, 20);
    lv_obj_set_align(ui_labelBMP384Value, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelBMP384Value, "N/A");
    lv_obj_set_style_text_font(ui_labelBMP384Value, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelmBarSymbol = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelmBarSymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelmBarSymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelmBarSymbol, 139);
    lv_obj_set_y(ui_labelmBarSymbol, 20);
    lv_obj_set_align(ui_labelmBarSymbol, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelmBarSymbol, "mBar");
    lv_obj_set_style_text_font(ui_labelmBarSymbol, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelOrientation = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelOrientation, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelOrientation, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelOrientation, -119);
    lv_obj_set_y(ui_labelOrientation, 67);
    lv_obj_set_align(ui_labelOrientation, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelOrientation, "Orientation");
    lv_obj_set_style_text_font(ui_labelOrientation, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelorientXvalue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelorientXvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelorientXvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelorientXvalue, -139);
    lv_obj_set_y(ui_labelorientXvalue, 83);
    lv_obj_set_align(ui_labelorientXvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelorientXvalue, "N/A");
    lv_obj_clear_flag(ui_labelorientXvalue, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelorientXvalue, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelorientXvalue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar3 = lv_bar_create(ui_ApplicationScreen);
    lv_bar_set_value(ui_Bar3, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_Bar3, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar3, 320);
    lv_obj_set_height(ui_Bar3, 1);
    lv_obj_set_x(ui_Bar3, 0);
    lv_obj_set_y(ui_Bar3, 95);
    lv_obj_set_align(ui_Bar3, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Bar3, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_labelDegreesymbol1 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelDegreesymbol1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelDegreesymbol1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelDegreesymbol1, -118);
    lv_obj_set_y(ui_labelDegreesymbol1, 84);
    lv_obj_set_align(ui_labelDegreesymbol1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelDegreesymbol1, "°");
    lv_obj_set_style_text_font(ui_labelDegreesymbol1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelorientYvalue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelorientYvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelorientYvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelorientYvalue, -91);
    lv_obj_set_y(ui_labelorientYvalue, 83);
    lv_obj_set_align(ui_labelorientYvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelorientYvalue, "N/A");
    lv_obj_clear_flag(ui_labelorientYvalue, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelorientYvalue, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelorientYvalue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelDegreesymbol2 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelDegreesymbol2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelDegreesymbol2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelDegreesymbol2, -71);
    lv_obj_set_y(ui_labelDegreesymbol2, 84);
    lv_obj_set_align(ui_labelDegreesymbol2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelDegreesymbol2, "°");
    lv_obj_set_style_text_font(ui_labelDegreesymbol2, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelorientZvalue = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelorientZvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelorientZvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelorientZvalue, -41);
    lv_obj_set_y(ui_labelorientZvalue, 83);
    lv_obj_set_align(ui_labelorientZvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelorientZvalue, "N/A");
    lv_obj_clear_flag(ui_labelorientZvalue, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelorientZvalue, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelorientZvalue, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelDegreesymbol3 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelDegreesymbol3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelDegreesymbol3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelDegreesymbol3, -19);
    lv_obj_set_y(ui_labelDegreesymbol3, 84);
    lv_obj_set_align(ui_labelDegreesymbol3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelDegreesymbol3, "°");
    lv_obj_set_style_text_font(ui_labelDegreesymbol3, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelAcceleration = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelAcceleration, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelAcceleration, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelAcceleration, 114);
    lv_obj_set_y(ui_labelAcceleration, 67);
    lv_obj_set_align(ui_labelAcceleration, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelAcceleration, "Acceleration");
    lv_obj_set_style_text_font(ui_labelAcceleration, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelg1Value = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelg1Value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelg1Value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelg1Value, 33);
    lv_obj_set_y(ui_labelg1Value, 83);
    lv_obj_set_align(ui_labelg1Value, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelg1Value, "N/A");
    lv_obj_clear_flag(ui_labelg1Value, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelg1Value, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelg1Value, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelGSymbol1 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelGSymbol1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelGSymbol1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelGSymbol1, 53);
    lv_obj_set_y(ui_labelGSymbol1, 83);
    lv_obj_set_align(ui_labelGSymbol1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelGSymbol1, "g");
    lv_obj_set_style_text_font(ui_labelGSymbol1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelg2Value = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelg2Value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelg2Value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelg2Value, 82);
    lv_obj_set_y(ui_labelg2Value, 83);
    lv_obj_set_align(ui_labelg2Value, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelg2Value, "N/A");
    lv_obj_clear_flag(ui_labelg2Value, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelg2Value, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelg2Value, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelGSymbol2 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelGSymbol2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelGSymbol2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelGSymbol2, 103);
    lv_obj_set_y(ui_labelGSymbol2, 83);
    lv_obj_set_align(ui_labelGSymbol2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelGSymbol2, "g");
    lv_obj_set_style_text_font(ui_labelGSymbol2, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelg3Value = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelg3Value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelg3Value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelg3Value, 130);
    lv_obj_set_y(ui_labelg3Value, 83);
    lv_obj_set_align(ui_labelg3Value, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelg3Value, "N/A");
    lv_obj_clear_flag(ui_labelg3Value, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelg3Value, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelg3Value, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelGSymbol3 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelGSymbol3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelGSymbol3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelGSymbol3, 150);
    lv_obj_set_y(ui_labelGSymbol3, 83);
    lv_obj_set_align(ui_labelGSymbol3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelGSymbol3, "g");
    lv_obj_set_style_text_font(ui_labelGSymbol3, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelxg24 = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelxg24, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelxg24, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelxg24, -83);
    lv_obj_set_y(ui_labelxg24, 108);
    lv_obj_set_align(ui_labelxg24, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelxg24, "xG24 - Development Kit");
    lv_obj_set_style_text_font(ui_labelxg24, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar4 = lv_bar_create(ui_ApplicationScreen);
    lv_bar_set_value(ui_Bar4, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_Bar4, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar4, 1);
    lv_obj_set_height(ui_Bar4, 25);
    lv_obj_set_x(ui_Bar4, -5);
    lv_obj_set_y(ui_Bar4, 108);
    lv_obj_set_align(ui_Bar4, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Bar4, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_labelbroadcasted = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelbroadcasted, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelbroadcasted, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelbroadcasted, 38);
    lv_obj_set_y(ui_labelbroadcasted, 108);
    lv_obj_set_align(ui_labelbroadcasted, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelbroadcasted, "Broadcasted:");
    lv_obj_set_style_text_font(ui_labelbroadcasted, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelsecond = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelsecond, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelsecond, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelsecond, 95);
    lv_obj_set_y(ui_labelsecond, 108);
    lv_obj_set_align(ui_labelsecond, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelsecond, "0");
    lv_obj_add_flag(ui_labelsecond, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_labelsecond, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_labelsecond, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_font(ui_labelsecond, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelsecago = lv_label_create(ui_ApplicationScreen);
    lv_obj_set_width(ui_labelsecago, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelsecago, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelsecago, 119);
    lv_obj_set_y(ui_labelsecago, 108);
    lv_obj_set_align(ui_labelsecago, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelsecago, "Disabled");
    lv_obj_set_style_text_color(ui_labelsecago,
                                lv_color_hex(0xFF0000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labelsecago, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_imgbthome, ui_event_imgbthome, LV_EVENT_ALL, NULL);
}