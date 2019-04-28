#ifndef __MACROS_H
#define __MACROS_H

#include <stdlib.h>
#include <string.h>
#include "stm32f0xx_hal.h"

#define MACRO_BUFFER_SIZE 100

typedef struct
{
    char Content[MACRO_BUFFER_SIZE];
    uint8_t Length;
}
MacroContext;

void GenerateGuid(MacroContext* context);
void WriteString(MacroContext* context, char* str);

#endif