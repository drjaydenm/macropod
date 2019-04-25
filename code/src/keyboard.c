#include "keyboard.h"

GPIOPin rows[] =
{
    { GPIOB, GPIO_PIN_0 },
    { GPIOB, GPIO_PIN_1 },
    { GPIOB, GPIO_PIN_3 },
    { GPIOB, GPIO_PIN_4 },
    { GPIOB, GPIO_PIN_5 }
};
const uint8_t rowCount = sizeof(rows) / sizeof(rows[0]);
GPIOPin columns[] =
{
    { GPIOA, GPIO_PIN_0 },
    { GPIOA, GPIO_PIN_1 },
    { GPIOA, GPIO_PIN_2 },
    { GPIOA, GPIO_PIN_3 }
};
const uint8_t columnCount = sizeof(columns) / sizeof(columns[0]);

KeyboardKey keys[] =
{
    // Row 0
    { KEY_MACRO_0, KEY_STATE_UP },
    { KEY_A, KEY_STATE_UP },
    { KEY_B, KEY_STATE_UP },
    { KEY_C, KEY_STATE_UP },
    // Row 1
    { KEY_D, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_G, KEY_STATE_UP },
    // Row 2
    { KEY_H, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    // Row 3
    { KEY_L, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    // Row 4
    { KEY_P, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP },
    { KEY_NONE, KEY_STATE_UP }
};
const uint8_t keyCount = sizeof(keys) / sizeof(keys[0]);

uint8_t macroKeyDown = 0;
uint8_t macroStep = 0;
uint8_t macroCount = 0;
uint8_t macroNextKeySame = 0;
uint32_t macroMillis = 0;
char macroContent[100] = {0};

void SetupKeyboard() {
    static GPIO_InitTypeDef GPIO_InitStruct;

    AnyKeyDown = 0;

    USBD_Init(&USBD_Device, &HID_Desc, 0);
    USBD_RegisterClass(&USBD_Device, &USBD_HID);
    USBD_Start(&USBD_Device);
    
    // Configure the scan line pins for input
    for (int i = 0; i < rowCount; i++)
    {
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Pin = rows[i].Pin;

        HAL_GPIO_Init(rows[i].Port, &GPIO_InitStruct);
    }
    for (int i = 0; i < columnCount; i++)
    {
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Pin = columns[i].Pin;

        HAL_GPIO_Init(columns[i].Port, &GPIO_InitStruct);
        HAL_GPIO_WritePin(columns[i].Port, columns[i].Pin, GPIO_PIN_SET);
    }
}

void ScanKeyboard() {
    // Only scan for key states if we aren't processing a macro
    if (!macroKeyDown)
    {
        ScanKeys();
    }
}

void UpdateKeyboard() {
    if (macroKeyDown)
    {
        HandleMacroKey();
    }
    else
    {
        HandleStandardKeys();
    }
}

void ScanKeys()
{
    uint32_t millis = HAL_GetTick();
    uint8_t keyIndex = 0;
    AnyKeyDown = 0;

    for (uint8_t i = 0; i < columnCount; i++)
    {
        HAL_GPIO_WritePin(columns[i].Port, columns[i].Pin, GPIO_PIN_RESET);

        for (uint8_t j = 0; j < rowCount; j++)
        {
            keyIndex = (columnCount * j) + i;

            if (keys[keyIndex].Key == KEY_NONE)
            {
                continue;
            }

            KeyState keyState = HAL_GPIO_ReadPin(rows[j].Port, rows[j].Pin);
            if (keyState != keys[keyIndex].State)
            {
                if (millis - keys[keyIndex].StateChangeMillis > DEBOUNCE_MILLIS)
                {
                    keys[keyIndex].State = keyState;
                    keys[keyIndex].StateChangeMillis = millis;
                }
            }

            if (keys[keyIndex].State == KEY_STATE_DOWN)
            {
                AnyKeyDown = 1;
            }

            if ((keys[keyIndex].Key == KEY_MACRO_0 || keys[keyIndex].Key == KEY_MACRO_1)
                && keys[keyIndex].State == KEY_STATE_DOWN)
            {
                BeginMacroKey(keys[keyIndex]);
            }
        }

        HAL_GPIO_WritePin(columns[i].Port, columns[i].Pin, GPIO_PIN_SET);
    }
}

void BeginMacroKey(KeyboardKey key)
{
    macroKeyDown = key.Key;
    macroMillis = HAL_GetTick();

    // Generate the output for the macrow
    if (key.Key == KEY_MACRO_0)
    {
        macroCount = GenerateGuid(macroContent);
    }
}

void EndMacroKey()
{
    macroKeyDown = 0;
    macroStep = 0;
    macroCount = 0;
    macroNextKeySame = 0;

    // Zero out the macro content
    memset(macroContent, 0, 100);
}

void HandleStandardKeys()
{
    uint8_t currentReportKey = 0;
    HIDKeyboardReport report = {0};

    if (!AnyKeyDown)
    {
        SendNullReport();
        return;
    }

    for (int i = 0; i < keyCount; i++)
    {
        if (keys[i].State == KEY_STATE_DOWN)
        {
            report.Keys[currentReportKey] = keys[i].Key;
            currentReportKey++;
        }

        // We can only send up to REPORT_MAX_KEYS keys at once
        if (currentReportKey >= REPORT_MAX_KEYS)
        {
            break;
        }
    }

    SendReport(&report);
}

void HandleMacroKey()
{
    HIDKeyboardReport report = {0};
    uint32_t currentTick = HAL_GetTick();

    if (macroNextKeySame && currentTick - macroMillis > MACRO_KEY_DELAY)
    {
        SendNullReport();
        macroNextKeySame = 0;
        macroMillis = HAL_GetTick();
        return;
    }

    if (!macroNextKeySame && macroStep < macroCount && currentTick - macroMillis > MACRO_KEY_DELAY)
    {
        report.Keys[0] = CharToKeyCode(macroContent[macroStep]);
        SendReport(&report);

        macroStep++;
        macroMillis = HAL_GetTick();

        // If the next and prev characters are the same, send a null report
        if (macroStep < macroCount && macroContent[macroStep] == macroContent[macroStep - 1])
        {
            macroNextKeySame = 1;
        }

        return;
    }

    if (macroStep >= macroCount)
    {
        SendNullReport();
        EndMacroKey();
    }
}

void SendNullReport() {
    HIDKeyboardReport report = {0};
    SendReport(&report);
}

void SendReport(const HIDKeyboardReport* report) {
    if (report == NULL) {
        return;
    }

    CopyReportToBuffer(report, _reportBuffer);

    USBD_HID_SendReport(&USBD_Device, _reportBuffer, REPORT_BUF_SIZE);
}

void CopyReportToBuffer(const HIDKeyboardReport* report, uint8_t* buffer)
{
    buffer[0] = report->Modifiers;
    buffer[1] = 0;
    buffer[2] = report->Keys[0];
    buffer[3] = report->Keys[1];
    buffer[4] = report->Keys[2];
    buffer[5] = report->Keys[3];
    buffer[6] = report->Keys[4];
    buffer[7] = report->Keys[5];
}

void ResetReport(HIDKeyboardReport* report)
{
    report->Modifiers = 0;
    report->Keys[0] = 0;
    report->Keys[1] = 0;
    report->Keys[2] = 0;
    report->Keys[3] = 0;
    report->Keys[4] = 0;
    report->Keys[5] = 0;
}