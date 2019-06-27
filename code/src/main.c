#include "main.h"

int main()
{
    HAL_Init();

    SystemClockConfig();

    SetupGPIO();
    SetupKeyboard();

    uint32_t lastFlashMillis = HAL_GetTick();
    uint32_t lastPauseMillis = HAL_GetTick();
    while (1)
    {
        ScanKeyboard();
        UpdateKeyboard();

        uint32_t millis = HAL_GetTick();
        if (millis - lastPauseMillis >= PAUSE_MILLIS)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);

            if (millis - lastFlashMillis >= PAUSE_MILLIS + FLASH_MILLIS)
            {
                lastPauseMillis = millis;
                lastFlashMillis = millis;
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
            }
        }
    }
}

void SetupGPIO()
{
    static GPIO_InitTypeDef GPIO_InitStruct;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();

    // Configure the onboard LED
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin = GPIO_PIN_10;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void SystemClockConfig(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;
    RCC_CRSInitTypeDef RCC_CRSInitStruct;

    // Enable HSI48 Oscillator to be used as system clock source
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    // Select HSI48 as USB clock source
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USB;
    PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

    // Select HSI48 as the system clock source, and configure HCLK and PCLK1 clock dividers
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);

    __HAL_RCC_CRS_CLK_ENABLE();

    RCC_CRSInitStruct.Prescaler = RCC_CRS_SYNC_DIV1;
    RCC_CRSInitStruct.Source = RCC_CRS_SYNC_SOURCE_USB;
    RCC_CRSInitStruct.ReloadValue = __HAL_RCC_CRS_RELOADVALUE_CALCULATE(48000000, 1000);
    RCC_CRSInitStruct.ErrorLimitValue = RCC_CRS_ERRORLIMIT_DEFAULT;
    RCC_CRSInitStruct.HSI48CalibrationValue = 0x20;
    HAL_RCCEx_CRSConfig(&RCC_CRSInitStruct);

    __HAL_RCC_PWR_CLK_ENABLE();
}
