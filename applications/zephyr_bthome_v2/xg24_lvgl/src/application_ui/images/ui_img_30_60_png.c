// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: BTHome v2_xG24_xG27_sensors_with_LVGL

#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

// IMAGE DATA: assets/30_60.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_30_60_png_data[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x02,0xB1,0x24,0x07,0xD9,0x24,0x0E,0xD0,0xC5,0x13,0xD0,0xE5,0x18,0xD9,0x26,0x1C,0xD8,0xC5,0x1E,0xD8,0xE5,0x18,0xD8,0xE3,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA8,0x00,0x03,0xE1,0x65,0x0B,0xD1,0x45,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x40,0x00,0x00,0x62,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xE7,0x04,0xE0,0xE5,0x11,0xD8,0xE4,0x20,0xD8,0xE5,0x30,0xD9,0x05,0x36,0xD8,0xE5,0x38,0xD9,0x05,0x37,0xD8,0xC5,0x2E,0xD8,0xC5,0x26,0xD8,0xE5,0x18,0xE0,0xE3,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0xA2,0x0C,0xD8,0xE4,0x1B,0xE0,0xE5,0x2A,0xD8,0xE5,0x39,0xD8,0xC5,0x43,0xD8,0xE5,0x48,0xD8,0xE5,0x43,0xD8,0xE5,0x39,0xE0,0xE5,0x2A,0xD8,0xE5,0x18,0xC0,0xE3,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0x00,0x04,0xD9,0x04,0x27,0xD8,0xE5,0x58,0xD8,0xE5,0x46,0xF9,0x86,0x0A,0x00,0x00,0x0D,0x00,0x00,0x80,0x00,0x00,0xAB,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x05,0x1E,0xD8,0xE5,0x3B,0xD0,0xE5,0x58,0xD8,0xE5,0x5B,0xD8,0xE5,0x55,0xD9,0x05,0x45,0xD8,0xC4,0x2F,0xD8,0xE4,0x20,0xD0,0xC5,0x13,0xF8,0x00,0x02,0x00,0x00,0x00,0x50,0x00,0x03,0xE0,0xE5,0x22,0xE0,0xE5,0x4B,0xE0,0xE5,0x79,0xE0,0xE5,0xA0,0xE0,0xE5,0xBC,0xE9,0x05,0xCE,0xE9,0x05,0xD9,0xE8,0xE5,0xE1,0xE1,0x05,0xE6,0xE8,0xE5,0xE2,0xE8,0xE5,0xD9,0xE9,0x05,0xCD,0xE0,0xE5,0xB9,0xE1,0x05,0x99,0xE0,0xE5,0x6C,0xD8,0xE5,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x65,0x0B,0xD8,0xE5,0x4B,0xE0,0xE5,0xBA,0xF1,0x05,0x9B,0xC9,0x05,0x46,0x00,0x00,0x51,0x00,0x00,0x77,0x00,0x00,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x84,0x0E,0xE0,0xE5,0x49,0xE0,0xE5,0x78,0xE0,0xE5,0x88,0xD8,0xE5,0x79,0xD0,0xE5,0x59,0xD8,0xC5,0x30,0xD0,0xE5,0x19,0xD9,0x24,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE8,0xA5,0x0C,0xD8,0xE5,0x49,0xE1,0x05,0x8F,0xE1,0x05,0xC9,0xE8,0xE5,0xE9,0xE8,0xE5,0xFD,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xF9,0xE9,0x05,0xD4,0xE1,0x05,0x64,0xB8,0xE3,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x71,0xF1,0x05,0xFF,0xF1,0x05,0xDC,0xD0,0xE5,0x7D,0x38,0x62,0x20,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE4,0x28,0xE0,0xE5,0x72,0xE0,0xE5,0xB1,0xE0,0xE5,0xB8,
    0xE0,0xE5,0x80,0xE0,0xE5,0x42,0xD8,0xE5,0x18,0xC9,0x86,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0x00,0x04,0xE0,0xE5,0x4E,0xE8,0xE5,0xA8,0xE8,0xE5,0xE8,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xF9,0x06,0xFF,0xF1,0x05,0xD7,0xD8,0xC5,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x61,0xE0,0xE5,0xFF,0xF1,0x05,0xFF,0xF1,0x05,0xF1,0xF9,0x06,0x75,0xFF,0xE0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD9,0x24,0x07,0xD8,0xE5,0x39,0xE8,0xE5,0x8B,0xE8,0xE5,0xD9,0xE8,0xE5,0xD8,0xE0,0xE5,0x8D,0xE1,0x05,0x35,0xE0,0xE7,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE4,0x21,0xE1,0x05,0x90,0xE8,0xE5,0xE9,0xE9,0x05,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xF6,0xE9,0x05,0x9B,0xD0,0xE5,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x03,0xD9,0x05,0x46,0xE0,0xE5,0xCF,0xE0,0xE5,0xFF,0xD0,0xE5,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0xF0,0xD9,0x05,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE7,0x09,0xE0,0xE5,0x43,0xE0,0xE5,0x9A,0xE8,0xE5,0xE7,0xF1,0x05,0xFD,0xE8,0xE5,0xB6,0xE0,0xE5,0x3B,0xF8,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x24,0xE9,0x05,0xB2,
    0xE9,0x05,0xFF,0xE1,0x05,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xD8,0xE5,0xC8,0xD8,0xE5,0x4F,0xD8,0xE4,0x20,0xC1,0x05,0x16,0xB8,0xE3,0x08,0xD9,0x24,0x07,0xD8,0xC5,0x1C,0xD8,0xE5,0x47,0xE0,0xE5,0x8D,0xE0,0xE5,0xE3,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xD8,0xE5,0x38,0xE1,0x05,0x96,0xE1,0x05,0xE7,0xE9,0x05,0xFF,0xF1,0x05,0xFF,0xE0,0xE5,0xA0,0xD8,0xA6,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE3,0x08,0xE0,0xE5,0x92,0xE9,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,
    0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0xFE,0xE0,0xE5,0xFA,0xE0,0xE5,0xF6,0xE0,0xE5,0xF1,0xE0,0xE5,0xEB,0xE0,0xE5,0xEA,0xE0,0xE5,0xEA,0xE0,0xE5,0xEA,0xE0,0xE5,0xEA,0xE0,0xE5,0xED,0xE0,0xE5,0xF3,0xE0,0xE5,0xF8,0xE0,0xE5,0xFC,0xE9,0x05,0xFF,0xE0,0xE5,0xFC,0xE9,0x05,0xE7,0xF1,0x05,0xD2,0xE9,0x05,0xB4,0xE1,0x05,0x96,0xD8,0xE5,0x93,0xE8,0xE5,0xBE,0xE0,0xE5,0xF1,0xE8,0xE5,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD0,0xE5,0x18,0xE0,0xE5,0x76,0xE8,0xE5,0xD8,0xE9,0x05,0xFF,0xE0,0xE5,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xC6,0xD0,0xE5,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0xE5,0x19,0xE8,0xE5,0xC3,0xF1,0x05,0xFF,0xD8,0xE5,0xF7,0xE0,0xE5,0xDB,0xE9,0x05,0xCC,0xE0,0xE5,0xC2,0xE0,0xE5,0xAE,0xE0,0xE5,0x99,0xE1,0x05,0x84,0xE1,0x05,0x75,
    0xD8,0xE5,0x66,0xD8,0xE5,0x58,0xD8,0xE5,0x4E,0xD8,0xE5,0x4B,0xD8,0xE5,0x4C,0xD8,0xE5,0x4B,0xD8,0xC5,0x4B,0xD8,0xE5,0x50,0xD0,0xE5,0x5E,0xD9,0x05,0x6E,0xE0,0xE5,0x7D,0xE0,0xE5,0x94,0xE0,0xE5,0xB1,0xE9,0x05,0xCF,0xF1,0x06,0xE8,0xF1,0x06,0xFF,0xF9,0x06,0xFF,0xF1,0x05,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xF8,0xD8,0xE5,0x4A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x32,0xE0,0xE5,0xB0,0xE9,0x05,0xFA,0xE9,0x05,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD1,0x45,0x06,0xE0,0xE5,0x78,0xF1,0x05,0xF6,0xE0,0xE5,0xFA,0xD8,0xE5,0x8D,0xD0,0xE5,0x38,0xB8,0xC6,0x14,0xC0,0xE3,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0xE3,0x08,0xC8,0xC4,0x14,0xC8,0xE5,0x23,0xD0,0xC5,0x41,0xD8,0xE5,0x77,0xE0,0xE5,0xBD,0xE9,0x05,0xF7,0xE1,0x05,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xF1,0x05,0xFF,0xE8,0xE5,0xB0,0xC1,0x24,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x3F,0xE9,0x05,0xCB,0xF1,0x05,0xFF,0xE0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xBA,0xD1,0x05,0x1D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD1,0x24,0x0D,0xE0,0xE5,0x66,0xE8,0xE5,0xBD,0xE1,0x05,0xCC,0xE8,0xE5,0xA8,0xE0,0xE5,0x90,0xD8,0xE5,0x88,0xD8,0xE5,0x80,0xD8,0xE5,0x7C,0xD8,0xE5,0x7A,0xD8,0xE5,0x73,0xE0,0xE5,0x67,0xE0,0xC4,0x53,0xD8,0xE5,0x32,0xB8,0xA5,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x1B,0xE1,0x05,0x73,0xE1,0x05,0xE5,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xD6,0xE0,0xE5,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x34,0xE8,0xE5,0xCB,0xF1,0x05,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFB,0xE0,0xE5,0xA4,0xD8,0xC5,0x32,0xA8,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xC5,0x1C,0xE0,0xE5,0x53,0xE0,0xE5,0x83,0xE1,0x05,0x9E,0xD8,0xE5,0xAA,0xD8,0xE5,0xAA,0xD8,0xE5,0xAC,0xE0,0xE5,0xAE,0xE0,0xE5,0xB1,0xD8,0xE5,0xB7,0xD8,0xE5,0xBA,0xE0,0xE5,0xB9,0xE0,0xE5,0xA7,0xE9,0x05,0x65,0xD1,0x05,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x02,0xE0,0xE5,0x78,0xE1,0x05,0xF6,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xE9,0x05,0xFF,0xE8,0xE5,0xD5,0xD9,0x05,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0xD0,0xA5,0x0B,0xE9,0x05,0xAA,0xF1,0x05,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0xDB,0xE1,0x05,0x8D,0xD8,0xE4,0x4D,0xD0,0xA4,0x26,0xC8,0x84,0x0F,0xB8,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xB8,0x07,0x04,0xD1,0x45,0x06,0xC8,0xC6,0x0A,0xE0,0xE3,0x12,0xD9,0x05,0x1F,0xD8,0xC4,0x2F,0xD8,0xC4,0x49,0xD8,0xE5,0x82,0xE0,0xE5,0xDD,0xE9,0x05,0xFA,0xE8,0xE5,0xAD,0xD8,0xC5,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x3E,0xE0,0xE5,0xE8,0xE9,0x05,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFC,0xE0,0xE5,0xB9,0xD8,0xE5,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xE5,0x43,0xE0,0xE5,0xF5,0xE1,0x05,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xF1,0x05,0xFF,0xF9,0x06,0xFF,0xE1,0x05,0xFE,0xE8,0xE5,0xD2,0xE8,0xE5,0xAA,0xD8,0xE5,0x8A,0xD8,0xE5,0x6C,0xE0,0xE5,0x5C,0xD8,0xE5,0x54,0xD8,0xE5,0x4D,0xD8,0xE5,0x48,0xD8,0xE5,0x47,0xD8,0xE5,0x46,0xD8,0xE5,0x46,0xD8,0xE5,0x49,0xD8,0xE5,0x4D,0xE0,0xE5,0x53,0xE0,0xE5,0x5D,0xD8,0xE5,0x6F,0xD8,0xE5,0x83,0xE0,0xE5,0x93,0xE8,0xE5,0xA6,0xE8,0xE5,0xBD,0xE1,0x05,0xD3,0xD8,0xE5,0xF0,0xE1,0x05,0xFF,0xF1,0x05,0xFF,0xE0,0xE5,0x7A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x79,0xE9,0x05,0xFE,
    0xF1,0x05,0xFF,0xE0,0xE5,0xE1,0xE1,0x05,0x85,0xD0,0xC5,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x05,0x77,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0xEF,0xE0,0xE5,0xAC,0xD8,0xE5,0x94,0xE0,0xE5,0xBE,0xE9,0x05,0xE1,0xF1,0x05,0xF4,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xF6,0xE0,0xE5,0xF0,0xE0,0xE5,0xE9,0xE9,0x05,0xE5,0xE8,0xE5,0xE4,0xE8,0xE5,0xE4,0xE9,0x05,0xE5,0xE0,0xE5,0xEA,0xE1,0x05,0xEE,0xE1,0x05,0xF5,0xE0,0xE5,0xFC,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFA,0xE0,0xE5,0x67,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE9,0x05,0x5F,0xF1,0x05,0xEE,0xF1,0x06,0xEA,0xE0,0xE5,0xA2,0xD8,0xE5,0x41,0x7B,0xEF,0x02,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x05,0x77,0xE1,0x05,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xE9,0x05,0xFF,0xE8,0xE5,0xC1,0xD8,0xE5,0x59,0xC8,0xC4,0x15,0xD9,0x24,0x07,0xD0,0xC5,0x1C,0xD0,0xC5,0x38,0xD8,0xC5,0x5E,0xD8,0xE5,0xBE,0xE1,0x05,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFC,0xE9,0x05,0x92,0xE0,0xC5,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x22,0xE0,0xE5,0x82,0xE9,0x05,0xDA,0xE9,0x05,0xB1,0xE0,0xE5,0x4D,0xC9,0x04,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xD0,0xC5,0x3C,0xE1,0x05,0xEC,0xE9,0x05,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xF3,0xE0,0xE5,0x90,0xD8,0xE5,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x42,0xE9,0x05,0xD7,0xE1,0x05,0xFF,0xD8,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xD8,0xE1,0x05,0x76,0xD0,0xE5,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xA5,0x16,0xD8,0xE5,0x50,0xE0,0xE5,0x90,0xE0,0xE5,0x98,0xE9,0x05,0x54,0xD0,0xE5,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x04,0xE0,0xE5,0x83,0xE8,0xE5,0xFA,0xE9,0x05,0xFF,
    0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xF1,0xE1,0x05,0x76,0xC0,0xE3,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE5,0x5D,0xE9,0x05,0xEF,0xF1,0x05,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xD8,0xE5,0xFF,0xE0,0xE5,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE1,0x05,0xF7,0xE0,0xE5,0xD0,0xE9,0x05,0x87,0xE1,0x05,0x33,0x78,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x01,0xD0,0x05,0x06,0xD0,0xA5,0x17,0xD8,0xE5,0x38,0xD0,0xE5,0x59,0xD8,0xE5,0x5C,0xE0,0xE5,0x3D,0xE9,0x06,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC9,0x24,0x0E,0xE0,0xE5,0x7D,0xE9,0x05,0xE7,0xE9,0x05,0xFF,0xF1,0x05,0xFF,0xE0,0xE5,0xD7,0xD1,0x05,0x1F,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD0,0xA5,0x0C,0xE0,0xE5,0x5D,0xE1,0x05,0xBD,0xE0,0xE5,0xE8,0xE0,0xE5,0xF9,0xE1,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE9,0x05,0xFF,0xE8,0xE5,0xFF,0xE1,0x05,0xFF,0xE0,0xE5,0xFA,0xE0,0xE5,0xEF,0xE1,0x05,0xDD,0xD8,0xE5,0xC2,0xE0,0xE5,0x93,0xE0,0xE5,0x5B,0xE0,0xE5,0x21,0x78,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE9,0x24,0x0E,0xD8,0xE4,0x21,0xD9,0x05,0x2E,0xD8,0xE5,0x2B,0xD8,0xE5,0x18,0xF9,0x86,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x02,0xE1,0x05,0x47,0xE1,0x05,0xA4,0xE9,0x05,0xE4,0xE9,0x05,0xF4,0xE0,0xE5,0x82,0xE1,0x24,0x1B,0xF8,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xA5,0x16,0xE0,0xE5,0x48,0xD8,0xE5,0x71,0xD8,0xE5,0x93,0xE0,0xE5,0xA8,0xE0,0xE5,0xAF,0xE0,0xE5,0xB6,0xE0,0xE5,0xB3,0xE0,0xE5,0xAB,0xD8,0xE5,0xA4,0xD8,0xE5,0x8F,0xD8,0xE5,0x74,0xD8,0xE5,0x59,0xE1,0x05,0x3A,0xD9,0x05,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x52,0xAA,0x03,0xD0,0x84,0x0D,0xD1,0x24,0x0D,0xAA,0xAA,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB9,0x45,0x0C,0xD8,0xE5,0x41,0xE0,0xE5,0x83,0xE0,0xE5,0xAD,0xE0,0xE5,0x81,0xD8,0xE5,0x44,0xD0,0xE4,0x1A,0xD9,0x24,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE9,0x45,0x0C,0xE0,0xC5,0x13,0xC8,0xE5,0x19,0xD1,0x04,0x16,0xD8,0xE5,0x10,0xC8,0xC6,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x27,0x1B,0xD8,0xE5,0x40,0xE0,0xE5,0x46,0xF9,0x26,0x2D,0xF0,0xE5,0x11,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x35,0x00,0x00,0x46,0x00,0x00,0x2E,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x17,0x00,0x00,0x14,0x00,0x00,0x00,0x38,0x61,0x11,0x38,0x21,0x23,0x60,0xC3,0x0A,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x1B,0x00,0x00,0x1B,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x00,0x47,0x00,0x00,0x38,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x0C,
    0x00,0x00,0x37,0x00,0x00,0x46,0x00,0x00,0x26,0x00,0x00,0x01,0x00,0x00,0x08,0x00,0x00,0x23,0x00,0x00,0x07,0x00,0x00,0x0E,0x00,0x00,0x21,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x21,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x24,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x00,0x39,0x00,0x00,0x45,0x00,0x00,0x2F,0x00,0x00,0x02,0x00,0x00,0x01,0x00,0x00,0x27,0x00,0x00,0x45,0x00,0x00,0x3A,0x00,0x00,0x0C,0x00,0x00,0x59,0x00,0x00,0xB9,0x00,0x00,0xB4,0x00,0x00,0xC3,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x6F,0x00,0x00,0x79,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x00,0x8F,0x00,0x00,0x1D,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x04,0x00,0x00,0x2F,0x00,0x00,0xB4,0x00,0x00,0xBB,0x00,0x00,0xCB,0x00,0x00,0x6D,0x00,0x00,0x01,0x00,0x00,0x66,0x00,0x00,0xBF,0x00,0x00,0xBD,0x00,0x00,0xB4,0x00,0x00,0x2C,
    0x00,0x00,0x19,0x00,0x00,0xA7,0x00,0x00,0x51,0x00,0x00,0x41,0x00,0x00,0x95,0x00,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0x00,0x94,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x00,0xBD,0x00,0x00,0x5E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0xC5,0x00,0x00,0xB5,0x00,0x00,0xB9,0x00,0x00,0x42,0x00,0x00,0x34,0x00,0x00,0xB1,0x00,0x00,0xB3,0x00,0x00,0xC2,0x00,0x00,0x66,0x00,0x00,0x96,0x00,0x00,0xA7,0x00,0x00,0x2C,0x00,0x00,0x74,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x85,0x00,0x00,0x92,0x00,0x00,0x00,0x00,0x00,0x5A,0x00,0x00,0xB1,0x00,0x00,0x26,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x91,0x00,0x00,0x91,0x00,0x00,0x05,0x00,0x00,0x56,0x00,0x00,0xB6,0x00,0x00,0x32,0x00,0x00,0x66,0x00,0x00,0x61,0x00,0x00,0x07,0x00,0x00,0x96,0x00,0x00,0x8A,0x00,0x00,0x3B,0x00,0x00,0xB5,0x00,0x00,0x57,0x00,0x00,0x18,0x00,0x00,0xDF,0x00,0x00,0xAF,0x00,0x00,0x53,
    0x00,0x00,0xAB,0x00,0x00,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5B,0x00,0x00,0xB0,0x00,0x00,0x26,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5E,0x00,0x00,0xFC,0x00,0x00,0x9A,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xA2,0x00,0x00,0x24,0x00,0x00,0x9D,0x00,0x00,0x75,0x00,0x00,0x64,0x00,0x00,0xD2,0x00,0x00,0x42,0x00,0x00,0x4E,0x00,0x00,0x59,0x00,0x00,0x59,0x00,0x00,0xCA,0x00,0x00,0x87,0x00,0x00,0x26,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x7F,0x00,0x00,0x8A,0x00,0x00,0x00,0x00,0x00,0x54,0x00,0x00,0xA6,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x88,0x00,0x00,0x88,0x00,0x00,0x04,0x00,0x00,0x55,0x00,0x00,0xA3,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x92,0x00,0x00,0x6C,0x00,0x00,0x14,0x00,0x00,0x9F,0x00,0x00,0x57,0x00,0x00,0x16,0x00,0x00,0xCC,0x00,0x00,0xDC,0x00,0x00,0x88,0x00,0x00,0x97,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x00,0x00,0xA6,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x84,0x00,0x00,0xB8,0x00,0x00,0xA8,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0xB5,0x00,0x00,0x65,0x00,0x00,0x9C,0x00,0x00,0x4B,0x00,0x00,0x34,0x00,0x00,0xBF,0x00,0x00,0xA9,0x00,0x00,0x41,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x4D,0x00,0x00,0xBF,0x00,0x00,0xBB,0x00,0x00,0x2D,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x8A,0x00,0x00,0x00,0x00,0x00,0x54,0x00,0x00,0xA5,0x00,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x88,0x00,0x00,0x88,0x00,0x00,0x04,0x00,0x00,0x53,0x00,0x00,0xA5,0x00,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x00,0x00,0x6F,0x00,0x00,0x19,0x00,0x00,0xA0,0x00,0x00,0x55,0x00,0x00,0x1C,0x00,0x00,0xA5,0x00,0x00,0xB2,0x00,0x00,0xE0,0x00,0x00,0xA5,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,
    0x00,0x00,0xA5,0x00,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x29,0x00,0x00,0xB0,0x00,0x00,0x81,0x00,0x00,0xAF,0x00,0x00,0x4B,0x00,0x00,0x00,0x00,0x00,0x6D,0x00,0x00,0xD7,0x00,0x00,0xB2,0x00,0x00,0xB0,0x00,0x00,0x37,0x00,0x00,0x00,0x00,0x00,0x2B,0x00,0x00,0x9A,0x00,0x00,0xD2,0x00,0x00,0x52,0x00,0x00,0x37,0x00,0x00,0x1D,0x00,0x00,0x1F,0x00,0x00,0xC2,0x00,0x00,0x68,0x00,0x00,0x01,0x00,0x00,0x7E,0x00,0x00,0x8B,0x00,0x00,0x00,0x00,0x00,0x56,0x00,0x00,0xA4,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x8A,0x00,0x00,0x8A,0x00,0x00,0x05,0x00,0x00,0x57,0x00,0x00,0xA2,0x00,0x00,0x01,0x00,0x00,0x26,0x00,0x00,0x3A,0x00,0x00,0x07,0x00,0x00,0x92,0x00,0x00,0x6B,0x00,0x00,0x10,0x00,0x00,0xA0,0x00,0x00,0x59,0x00,0x00,0x21,0x00,0x00,0x9B,0x00,0x00,0x60,0x00,0x00,0xE5,0x00,0x00,0xC1,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x00,0x00,0xA4,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x4A,0x00,0x00,0xE1,0x00,0x00,0xC8,0x00,0x00,0xDD,0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00,0x79,0x00,0x00,0x93,0x00,0x00,0x1E,0x00,0x00,0x90,0x00,0x00,0x74,0x00,0x00,0x26,0x00,0x00,0x31,0x00,0x00,0x00,0x00,0x00,0x92,0x00,0x00,0x99,0x00,0x00,0x81,0x00,0x00,0xB8,0x00,0x00,0x7C,0x00,0x00,0xC3,0x00,0x00,0x56,0x00,0x00,0x01,0x00,0x00,0x83,0x00,0x00,0x8F,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x00,0xCC,0x00,0x00,0x93,0x00,0x00,0x64,0x00,0x00,0x20,0x00,0x00,0x89,0x00,0x00,0x8E,0x00,0x00,0x04,0x00,0x00,0x49,0x00,0x00,0xC5,0x00,0x00,0x80,0x00,0x00,0xBC,0x00,0x00,0x8D,0x00,0x00,0x06,0x00,0x00,0x89,0x00,0x00,0xB5,0x00,0x00,0x8A,0x00,0x00,0xC6,0x00,0x00,0x48,0x00,0x00,0x22,0x00,0x00,0xAA,0x00,0x00,0x30,0x00,0x00,0x9A,0x00,0x00,0xCD,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x51,0x00,0x00,0xCC,0x00,0x00,0x93,0x00,0x00,0x62,0x00,0x00,0x1C,0x00,0x00,0x83,0x00,0x00,0xB8,0x00,0x00,0x53,0x00,0x00,0x8F,
    0x00,0x00,0xAB,0x00,0x00,0x0C,0x00,0x00,0x72,0x00,0x00,0xC0,0x00,0x00,0x79,0x00,0x00,0xBC,0x00,0x00,0x67,0x00,0x00,0x51,0x00,0x00,0xC7,0x00,0x00,0x81,0x00,0x00,0xAC,0x00,0x00,0x82,0x00,0x00,0x25,0x00,0x00,0x81,0x00,0x00,0x94,0x00,0x00,0x68,0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x45,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x77,0x00,0x00,0x96,0x00,0x00,0x79,0x00,0x00,0x21,0x00,0x00,0x3C,0x00,0x00,0x43,0x00,0x00,0x01,0x00,0x00,0x0D,0x00,0x00,0x69,0x00,0x00,0x95,0x00,0x00,0x85,0x00,0x00,0x32,0x00,0x00,0x00,0x00,0x00,0x2C,0x00,0x00,0x81,0x00,0x00,0x94,0x00,0x00,0x67,0x00,0x00,0x0E,0x00,0x00,0x13,0x00,0x00,0x55,0x00,0x00,0x11,0x00,0x00,0x2C,0x00,0x00,0x5C,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x77,0x00,0x00,0x96,0x00,0x00,0x77,0x00,0x00,0x24,0x00,0x00,0x4D,0x00,0x00,0x39,0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0x00,0x5D,0x00,0x00,0x13,0x00,0x00,0x2E,0x00,0x00,0x83,
    0x00,0x00,0x93,0x00,0x00,0x72,0x00,0x00,0x14,0x00,0x00,0x13,0x00,0x00,0x6E,0x00,0x00,0x95,0x00,0x00,0x7F,0x00,0x00,0x22,
};
const lv_img_dsc_t ui_img_30_60_png = {
    .header.always_zero = 0,
    .header.w = 60,
    .header.h = 30,
    .data_size = sizeof(ui_img_30_60_png_data),
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = ui_img_30_60_png_data
};

