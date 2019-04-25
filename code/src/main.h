#ifndef __MAIN_H
#define __MAIN_H

#include <stdint.h>

#ifdef MCU_CLASS_F0
    #include "stm32f0xx.h"
    #include "stm32f0xx_hal.h"
#elif MCU_CLASS_L0
    #include "stm32l0xx.h"
    #include "stm32l0xx_hal.h"
#endif

#include "gpio_pin.h"
#include "keyboard.h"

#define FLASH_MILLIS 500
#define QUICK_FLASH_MILLIS 50

void SetupGPIO();
void SystemClockConfig(void);

#endif