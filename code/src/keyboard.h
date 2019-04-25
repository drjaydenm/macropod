#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "usbd_desc.h"
#include "usbd_hid.h"
#include "gpio_pin.h"
#include "keys.h"
#include "macros.h"

#define REPORT_BUF_SIZE 8
#define REPORT_MAX_KEYS 6
#define DEBOUNCE_MILLIS 30
#define MACRO_KEY_DELAY 20
#define POST_MACRO_DELAY 500

typedef struct
{
    uint8_t Modifiers;
    uint8_t Keys[REPORT_MAX_KEYS];
}
HIDKeyboardReport;

typedef enum
{
    KEY_STATE_DOWN = 0,
    KEY_STATE_UP = 1
}
KeyState;

typedef struct
{
    uint8_t Key;
    KeyState State;
    uint32_t StateChangeMillis;
}
KeyboardKey;

__ALIGN_BEGIN uint8_t _reportBuffer[REPORT_BUF_SIZE] __ALIGN_END;
USBD_HandleTypeDef USBD_Device;
uint8_t AnyKeyDown;

void SetupKeyboard();
void ScanKeyboard();
void UpdateKeyboard();
void ScanKeys();
void BeginMacroKey(KeyboardKey key);
void EndMacroKey();
void HandleStandardKeys();
void HandleMacroKey();
void SendNullReport();
void SendReport(const HIDKeyboardReport* report);
void CopyReportToBuffer(const HIDKeyboardReport* report, uint8_t* buffer);
void ResetReport(HIDKeyboardReport* report);

#endif