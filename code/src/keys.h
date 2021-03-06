#ifndef __KEYS_H
#define __KEYS_H

#include <stdint.h>
#include <ctype.h>
#include "macros.h"

#ifdef KEY_MAPPINGS_DEFINED
    #include "key_mappings.h"
#endif

#ifndef MACRO_KEY_0
    #define MACRO_KEY_0
#endif
#ifndef MACRO_KEY_1
    #define MACRO_KEY_1
#endif
#ifndef MACRO_KEY_2
    #define MACRO_KEY_2
#endif
#ifndef MACRO_KEY_3
    #define MACRO_KEY_3
#endif
#ifndef MACRO_KEY_4
    #define MACRO_KEY_4
#endif
#ifndef MACRO_KEY_5
    #define MACRO_KEY_5
#endif
#ifndef MACRO_KEY_6
    #define MACRO_KEY_6
#endif
#ifndef MACRO_KEY_7
    #define MACRO_KEY_7
#endif
#ifndef MACRO_KEY_8
    #define MACRO_KEY_8
#endif
#ifndef MACRO_KEY_9
    #define MACRO_KEY_9
#endif
#ifndef MACRO_KEY_10
    #define MACRO_KEY_10
#endif
#ifndef MACRO_KEY_11
    #define MACRO_KEY_11
#endif
#ifndef MACRO_KEY_12
    #define MACRO_KEY_12
#endif
#ifndef MACRO_KEY_13
    #define MACRO_KEY_13
#endif
#ifndef MACRO_KEY_14
    #define MACRO_KEY_14
#endif
#ifndef MACRO_KEY_15
    #define MACRO_KEY_15
#endif
#ifndef MACRO_KEY_16
    #define MACRO_KEY_16
#endif
#ifndef MACRO_KEY_17
    #define MACRO_KEY_17
#endif
#ifndef MACRO_KEY_18
    #define MACRO_KEY_18
#endif
#ifndef MACRO_KEY_19
    #define MACRO_KEY_19
#endif

// Modifier key codes
#define KEY_MOD_NONE   0x00
#define KEY_MOD_LCTRL  0x01
#define KEY_MOD_LSHIFT 0x02
#define KEY_MOD_LALT   0x04
#define KEY_MOD_LMETA  0x08
#define KEY_MOD_RCTRL  0x10
#define KEY_MOD_RSHIFT 0x20
#define KEY_MOD_RALT   0x40
#define KEY_MOD_RMETA  0x80

// Key scan codes
// Take a look at Page 53 https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
#define KEY_NONE            ((uint8_t)0x00)
#define KEY_ERROR_ROLL_OVER ((uint8_t)0x01)
#define KEY_POST_FAIL       ((uint8_t)0x02)
#define KEY_ERROR_UNDEFINED ((uint8_t)0x03)

#define KEY_A ((uint8_t)0x04)
#define KEY_B ((uint8_t)0x05)
#define KEY_C ((uint8_t)0x06)
#define KEY_D ((uint8_t)0x07)
#define KEY_E ((uint8_t)0x08)
#define KEY_F ((uint8_t)0x09)
#define KEY_G ((uint8_t)0x0A)
#define KEY_H ((uint8_t)0x0B)
#define KEY_I ((uint8_t)0x0C)
#define KEY_J ((uint8_t)0x0D)
#define KEY_K ((uint8_t)0x0E)
#define KEY_L ((uint8_t)0x0F)
#define KEY_M ((uint8_t)0x10)
#define KEY_N ((uint8_t)0x11)
#define KEY_O ((uint8_t)0x12)
#define KEY_P ((uint8_t)0x13)
#define KEY_Q ((uint8_t)0x14)
#define KEY_R ((uint8_t)0x15)
#define KEY_S ((uint8_t)0x16)
#define KEY_T ((uint8_t)0x17)
#define KEY_U ((uint8_t)0x18)
#define KEY_V ((uint8_t)0x19)
#define KEY_W ((uint8_t)0x1A)
#define KEY_X ((uint8_t)0x1B)
#define KEY_Y ((uint8_t)0x1C)
#define KEY_Z ((uint8_t)0x1D)

#define KEY_1 ((uint8_t)0x1E)
#define KEY_2 ((uint8_t)0x1F)
#define KEY_3 ((uint8_t)0x20)
#define KEY_4 ((uint8_t)0x21)
#define KEY_5 ((uint8_t)0x22)
#define KEY_6 ((uint8_t)0x23)
#define KEY_7 ((uint8_t)0x24)
#define KEY_8 ((uint8_t)0x25)
#define KEY_9 ((uint8_t)0x26)
#define KEY_0 ((uint8_t)0x27)

#define KEY_ENTER      ((uint8_t)0x28)
#define KEY_ESC        ((uint8_t)0x29)
#define KEY_BACKSPACE  ((uint8_t)0x2A)
#define KEY_TAB        ((uint8_t)0x2B)
#define KEY_SPACE      ((uint8_t)0x2C)
#define KEY_MINUS      ((uint8_t)0x2D)
#define KEY_EQUAL      ((uint8_t)0x2E)
#define KEY_LEFTBRACE  ((uint8_t)0x2F)
#define KEY_RIGHTBRACE ((uint8_t)0x30)
#define KEY_BACKSLASH  ((uint8_t)0x31)
#define KEY_HASHTILDE  ((uint8_t)0x32)
#define KEY_SEMICOLON  ((uint8_t)0x33)
#define KEY_APOSTROPHE ((uint8_t)0x34)
#define KEY_GRAVE      ((uint8_t)0x35)
#define KEY_COMMA      ((uint8_t)0x36)
#define KEY_DOT        ((uint8_t)0x37)
#define KEY_SLASH      ((uint8_t)0x38)
#define KEY_CAPSLOCK   ((uint8_t)0x39)

#define KEY_F1  ((uint8_t)0x3A)
#define KEY_F2  ((uint8_t)0x3B)
#define KEY_F3  ((uint8_t)0x3C)
#define KEY_F4  ((uint8_t)0x3D)
#define KEY_F5  ((uint8_t)0x3E)
#define KEY_F6  ((uint8_t)0x3F)
#define KEY_F7  ((uint8_t)0x40)
#define KEY_F8  ((uint8_t)0x41)
#define KEY_F9  ((uint8_t)0x42)
#define KEY_F10 ((uint8_t)0x43)
#define KEY_F11 ((uint8_t)0x44)
#define KEY_F12 ((uint8_t)0x45)

#define KEY_SYSRQ      ((uint8_t)0x46)
#define KEY_SCROLLLOCK ((uint8_t)0x47)
#define KEY_PAUSE      ((uint8_t)0x48)
#define KEY_INSERT     ((uint8_t)0x49)
#define KEY_HOME       ((uint8_t)0x4A)
#define KEY_PAGEUP     ((uint8_t)0x4B)
#define KEY_DELETE     ((uint8_t)0x4C)
#define KEY_END        ((uint8_t)0x4D)
#define KEY_PAGEDOWN   ((uint8_t)0x4E)
#define KEY_RIGHT      ((uint8_t)0x4F)
#define KEY_LEFT       ((uint8_t)0x50)
#define KEY_DOWN       ((uint8_t)0x51)
#define KEY_UP         ((uint8_t)0x52)

#define KEY_NUMLOCK         ((uint8_t)0x53)
#define KEY_KEYPAD_SLASH    ((uint8_t)0x54)
#define KEY_KEYPAD_ASTERISK ((uint8_t)0x55)
#define KEY_KEYPAD_MINUS    ((uint8_t)0x56)
#define KEY_KEYPAD_PLUS     ((uint8_t)0x57)
#define KEY_KEYPAD_ENTER    ((uint8_t)0x58)
#define KEY_KEYPAD_1        ((uint8_t)0x59)
#define KEY_KEYPAD_2        ((uint8_t)0x5A)
#define KEY_KEYPAD_3        ((uint8_t)0x5B)
#define KEY_KEYPAD_4        ((uint8_t)0x5C)
#define KEY_KEYPAD_5        ((uint8_t)0x5D)
#define KEY_KEYPAD_6        ((uint8_t)0x5E)
#define KEY_KEYPAD_7        ((uint8_t)0x5F)
#define KEY_KEYPAD_8        ((uint8_t)0x60)
#define KEY_KEYPAD_9        ((uint8_t)0x61)
#define KEY_KEYPAD_0        ((uint8_t)0x62)
#define KEY_KEYPAD_DOT      ((uint8_t)0x63)

#define KEY_102ND        ((uint8_t)0x64)
#define KEY_COMPOSE      ((uint8_t)0x65)
#define KEY_POWER        ((uint8_t)0x66)
#define KEY_KEYPAD_EQUAL ((uint8_t)0x67)

#define KEY_F13 ((uint8_t)0x68)
#define KEY_F14 ((uint8_t)0x69)
#define KEY_F15 ((uint8_t)0x6A)
#define KEY_F16 ((uint8_t)0x6B)
#define KEY_F17 ((uint8_t)0x6C)
#define KEY_F18 ((uint8_t)0x6D)
#define KEY_F19 ((uint8_t)0x6E)
#define KEY_F20 ((uint8_t)0x6F)
#define KEY_F21 ((uint8_t)0x70)
#define KEY_F22 ((uint8_t)0x71)
#define KEY_F23 ((uint8_t)0x72)
#define KEY_F24 ((uint8_t)0x73)

#define KEY_KEYPAD_AT  ((uint8_t)0xCE)

#define KEY_LEFTCTRL   ((uint8_t)0xE0)
#define KEY_LEFTSHIFT  ((uint8_t)0xE1)
#define KEY_LEFTALT    ((uint8_t)0xE2)
#define KEY_LEFTMETA   ((uint8_t)0xE3)
#define KEY_RIGHTCTRL  ((uint8_t)0xE4)
#define KEY_RIGHTSHIFT ((uint8_t)0xE5)
#define KEY_RIGHTALT   ((uint8_t)0xE6)
#define KEY_RIGHTMETA  ((uint8_t)0xE7)

#define KEY_MACRO_0  ((uint8_t)0xA0)
#define KEY_MACRO_1  ((uint8_t)0xA1)
#define KEY_MACRO_2  ((uint8_t)0xA2)
#define KEY_MACRO_3  ((uint8_t)0xA3)
#define KEY_MACRO_4  ((uint8_t)0xA4)
#define KEY_MACRO_5  ((uint8_t)0xA5)
#define KEY_MACRO_6  ((uint8_t)0xA6)
#define KEY_MACRO_7  ((uint8_t)0xA7)
#define KEY_MACRO_8  ((uint8_t)0xA8)
#define KEY_MACRO_9  ((uint8_t)0xA9)
#define KEY_MACRO_10 ((uint8_t)0xAA)
#define KEY_MACRO_11 ((uint8_t)0xAB)
#define KEY_MACRO_12 ((uint8_t)0xAC)
#define KEY_MACRO_13 ((uint8_t)0xAD)
#define KEY_MACRO_14 ((uint8_t)0xAE)
#define KEY_MACRO_15 ((uint8_t)0xAF)
#define KEY_MACRO_16 ((uint8_t)0xB0)
#define KEY_MACRO_17 ((uint8_t)0xB1)
#define KEY_MACRO_18 ((uint8_t)0xB2)
#define KEY_MACRO_19 ((uint8_t)0xB3)

#define IS_MACRO_KEY(__KEY__) (((__KEY__) == KEY_MACRO_0) ||\
                              ((__KEY__) == KEY_MACRO_1)  ||\
                              ((__KEY__) == KEY_MACRO_2)  ||\
                              ((__KEY__) == KEY_MACRO_3)  ||\
                              ((__KEY__) == KEY_MACRO_4)  ||\
                              ((__KEY__) == KEY_MACRO_5)  ||\
                              ((__KEY__) == KEY_MACRO_6)  ||\
                              ((__KEY__) == KEY_MACRO_7)  ||\
                              ((__KEY__) == KEY_MACRO_8)  ||\
                              ((__KEY__) == KEY_MACRO_9)  ||\
                              ((__KEY__) == KEY_MACRO_10) ||\
                              ((__KEY__) == KEY_MACRO_11) ||\
                              ((__KEY__) == KEY_MACRO_12) ||\
                              ((__KEY__) == KEY_MACRO_13) ||\
                              ((__KEY__) == KEY_MACRO_14) ||\
                              ((__KEY__) == KEY_MACRO_15) ||\
                              ((__KEY__) == KEY_MACRO_16) ||\
                              ((__KEY__) == KEY_MACRO_17) ||\
                              ((__KEY__) == KEY_MACRO_18) ||\
                              ((__KEY__) == KEY_MACRO_19))

uint8_t CharToKeyCode(char c);
uint8_t CharModifierKeys(char c);
void GetKeyContent(uint8_t key, MacroContext* context);

#endif
