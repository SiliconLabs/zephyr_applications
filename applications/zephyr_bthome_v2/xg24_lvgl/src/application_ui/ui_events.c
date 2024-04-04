// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: [ZE-VA]_BTHome v2_xG24_xG27_sensors_with_LVGL

#include "ui.h"

bool broadcast_enabled = false;
bool config_broadcast_interval = false;
bool config_device_name = false;
bool config_encryption_key = false;
uint16_t broadcast_interval = 2000;


void bthome_pressed_handle(lv_event_t * e)
{
	(void)e;

  lv_disp_load_scr(ui_SettingScreen);
}

void swboardcast_enable_callback(lv_event_t * e)
{
  (void)e;
  
  broadcast_enabled = (broadcast_enabled) ? false : true;
}

void back_pressed_callback(lv_event_t * e)
{
  (void)e;

  lv_disp_load_scr(ui_ApplicationScreen);
  config_broadcast_interval = false;
  config_device_name = false;
  config_encryption_key = false;
}

void keyboard_ready_callback(lv_event_t * e)
{
  (void)e;

 if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_txtdevicename) {
     config_device_name = true;
 } else if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_txtboardcastperiod) {
     config_broadcast_interval = true;
 } else if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_txtencryptkey) {
     config_encryption_key = true;
 }
}