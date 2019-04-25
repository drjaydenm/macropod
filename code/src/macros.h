#ifndef __MACROS_H
#define __MACROS_H

#include <stdlib.h>
#include <string.h>
#include "stm32f0xx_hal.h"

#define MACRO_BUFFER_SIZE 100

uint8_t GenerateGuid(char* buffer);
uint8_t WriteString(char* buffer, char* str);

#endif