#include "macros.h"

void GenerateGuid(MacroContext* context)
{
    srand(HAL_GetTick());
    static const char *guidTemplate = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";
    static const char *guidCharacters = "0123456789ABCDEF-";
    uint8_t guidLength = strlen(guidTemplate);
    uint8_t contentStart = context->Length;

    for (uint8_t i = 0; i <= guidLength; i++)
    {
        uint8_t r = rand() % 16;
        char c = ' ';

        switch (guidTemplate[i])
        {
            case 'x': { c = guidCharacters[r]; } break;
            case 'y': { c = guidCharacters[r & (0x03 | 0x08)]; } break;
            case '-': { c = '-'; } break;
            case '4': { c = '4'; } break;
        }

        context->Content[i + contentStart] = (i < guidLength) ? c : 0x00;
    }

    context->Length += guidLength;
}

void WriteString(MacroContext* context, char* str)
{
    uint8_t strLen = strlen(str);
    strLen = strLen <= MACRO_BUFFER_SIZE ? strLen : MACRO_BUFFER_SIZE;
    uint8_t contentStart = context->Length;

    for (uint8_t i = 0; i < strLen; i++)
    {
        context->Content[i + contentStart] = str[i];
    }

    context->Length += strLen;
}