// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: BTHome v2_xG24_xG27_sensors_with_LVGL

#include "../ui.h"

void ui_SettingScreen_screen_init(void)
{
    ui_SettingScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SettingScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bar5 = lv_bar_create(ui_SettingScreen);
    lv_bar_set_value(ui_Bar5, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_Bar5, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar5, 320);
    lv_obj_set_height(ui_Bar5, 1);
    lv_obj_set_x(ui_Bar5, 0);
    lv_obj_set_y(ui_Bar5, -90);
    lv_obj_set_align(ui_Bar5, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Bar5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Bar5, lv_color_hex(0x040000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Bar5, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_imgBTHome = lv_img_create(ui_SettingScreen);
    lv_img_set_src(ui_imgBTHome, &ui_img_25_png);
    lv_obj_set_width(ui_imgBTHome, LV_SIZE_CONTENT);   /// 84
    lv_obj_set_height(ui_imgBTHome, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_imgBTHome, 111);
    lv_obj_set_y(ui_imgBTHome, -105);
    lv_obj_set_align(ui_imgBTHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgBTHome, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgBTHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_labelSetting = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_labelSetting, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelSetting, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelSetting, -7);
    lv_obj_set_y(ui_labelSetting, -105);
    lv_obj_set_align(ui_labelSetting, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelSetting, "Settings");
    lv_obj_set_style_text_font(ui_labelSetting, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_btnback = lv_btn_create(ui_SettingScreen);
    lv_obj_set_width(ui_btnback, 84);
    lv_obj_set_height(ui_btnback, 24);
    lv_obj_set_x(ui_btnback, -115);
    lv_obj_set_y(ui_btnback, -106);
    lv_obj_set_align(ui_btnback, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_btnback, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_btnback, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_btnback, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_btnback, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_btnback, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBack = lv_label_create(ui_btnback);
    lv_obj_set_width(ui_LabelBack, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBack, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelBack, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBack, "Back");

    ui_labelBoardcastenable = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_labelBoardcastenable, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelBoardcastenable, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelBoardcastenable, -92);
    lv_obj_set_y(ui_labelBoardcastenable, -78);
    lv_obj_set_align(ui_labelBoardcastenable, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelBoardcastenable, "Boardcasting Enable");
    lv_obj_set_style_text_font(ui_labelBoardcastenable, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelDeviceName = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_labelDeviceName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelDeviceName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelDeviceName, -114);
    lv_obj_set_y(ui_labelDeviceName, -52);
    lv_obj_set_align(ui_labelDeviceName, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelDeviceName, "Device Name");
    lv_obj_set_style_text_font(ui_labelDeviceName, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelboardcastperiod = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_labelboardcastperiod, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelboardcastperiod, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelboardcastperiod, -102);
    lv_obj_set_y(ui_labelboardcastperiod, -18);
    lv_obj_set_align(ui_labelboardcastperiod, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelboardcastperiod, "Broadcast period");
    lv_obj_set_style_text_font(ui_labelboardcastperiod, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelencryptkey = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_labelencryptkey, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelencryptkey, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelencryptkey, 6);
    lv_obj_set_y(ui_labelencryptkey, 127);
    lv_label_set_text(ui_labelencryptkey, "Encryption key");
    lv_obj_set_style_text_font(ui_labelencryptkey, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_swboardcastenable = lv_switch_create(ui_SettingScreen);
    lv_obj_set_width(ui_swboardcastenable, 41);
    lv_obj_set_height(ui_swboardcastenable, 17);
    lv_obj_set_x(ui_swboardcastenable, 133);
    lv_obj_set_y(ui_swboardcastenable, -78);
    lv_obj_set_align(ui_swboardcastenable, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_swboardcastenable, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_swboardcastenable, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_swboardcastenable, lv_color_hex(0x7CFC00), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_swboardcastenable, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(ui_swboardcastenable, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_swboardcastenable, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Keyboard1 = lv_keyboard_create(ui_SettingScreen);
    lv_obj_set_width(ui_Keyboard1, 314);
    lv_obj_set_height(ui_Keyboard1, 83);
    lv_obj_set_x(ui_Keyboard1, 0);
    lv_obj_set_y(ui_Keyboard1, 75);
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_CENTER);

    ui_txtdevicename = lv_textarea_create(ui_SettingScreen);
    lv_obj_set_width(ui_txtdevicename, 177);
    lv_obj_set_height(ui_txtdevicename, LV_SIZE_CONTENT);    /// 31
    lv_obj_set_x(ui_txtdevicename, 64);
    lv_obj_set_y(ui_txtdevicename, -51);
    lv_obj_set_align(ui_txtdevicename, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_txtdevicename, 30);
    lv_textarea_set_placeholder_text(ui_txtdevicename, "ZPBTxG24");
    lv_textarea_set_one_line(ui_txtdevicename, true);
    lv_obj_set_style_text_font(ui_txtdevicename, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_txtboardcastperiod = lv_textarea_create(ui_SettingScreen);
    lv_obj_set_width(ui_txtboardcastperiod, 177);
    lv_obj_set_height(ui_txtboardcastperiod, LV_SIZE_CONTENT);    /// 31
    lv_obj_set_x(ui_txtboardcastperiod, 64);
    lv_obj_set_y(ui_txtboardcastperiod, -18);
    lv_obj_set_align(ui_txtboardcastperiod, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_txtboardcastperiod, 30);
    lv_textarea_set_placeholder_text(ui_txtboardcastperiod, "2000");
    lv_textarea_set_one_line(ui_txtboardcastperiod, true);
    lv_obj_set_style_text_font(ui_txtboardcastperiod, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_txtencryptkey = lv_textarea_create(ui_SettingScreen);
    lv_obj_set_width(ui_txtencryptkey, 177);
    lv_obj_set_height(ui_txtencryptkey, LV_SIZE_CONTENT);    /// 31
    lv_obj_set_x(ui_txtencryptkey, 64);
    lv_obj_set_y(ui_txtencryptkey, 15);
    lv_obj_set_align(ui_txtencryptkey, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_txtencryptkey, 30);
    lv_textarea_set_placeholder_text(ui_txtencryptkey, "12345678123456781234567812345678");
    lv_textarea_set_one_line(ui_txtencryptkey, true);
    lv_obj_set_style_text_font(ui_txtencryptkey, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);



    lv_obj_add_event_cb(ui_btnback, ui_event_btnback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_swboardcastenable, ui_event_swboardcastenable, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Keyboard1, ui_event_Keyboard1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_txtdevicename, ui_event_txtdevicename, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_txtboardcastperiod, ui_event_txtboardcastperiod, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_txtencryptkey, ui_event_txtencryptkey, LV_EVENT_ALL, NULL);

}