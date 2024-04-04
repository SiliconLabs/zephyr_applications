// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: [ZE-VA]_BTHome v2_xG24_xG27_sensors_with_LVGL

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

extern bool broadcast_enabled;
extern bool config_broadcast_interval;
extern bool config_device_name;
extern bool config_encryption_key;
extern uint16_t broadcast_interval; 

void bthome_pressed_handle(lv_event_t * e);
void back_pressed_callback(lv_event_t * e);
void swboardcast_enable_callback(lv_event_t * e);
void keyboard_ready_callback(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
