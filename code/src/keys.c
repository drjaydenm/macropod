#include "keys.h"

uint8_t CharToKeyCode(char c)
{
    switch (c)
    {
        case 'a': case 'A': return KEY_A;
        case 'b': case 'B': return KEY_B;
        case 'c': case 'C': return KEY_C;
        case 'd': case 'D': return KEY_D;
        case 'e': case 'E': return KEY_E;
        case 'f': case 'F': return KEY_F;
        case 'g': case 'G': return KEY_G;
        case 'h': case 'H': return KEY_H;
        case 'i': case 'I': return KEY_I;
        case 'j': case 'J': return KEY_J;
        case 'k': case 'K': return KEY_K;
        case 'l': case 'L': return KEY_L;
        case 'm': case 'M': return KEY_M;
        case 'n': case 'N': return KEY_N;
        case 'o': case 'O': return KEY_O;
        case 'p': case 'P': return KEY_P;
        case 'q': case 'Q': return KEY_Q;
        case 'r': case 'R': return KEY_R;
        case 's': case 'S': return KEY_S;
        case 't': case 'T': return KEY_T;
        case 'u': case 'U': return KEY_U;
        case 'v': case 'V': return KEY_V;
        case 'w': case 'W': return KEY_W;
        case 'x': case 'X': return KEY_X;
        case 'y': case 'Y': return KEY_Y;
        case 'z': case 'Z': return KEY_Z;
        case '1': return KEY_1;
        case '2': return KEY_2;
        case '3': return KEY_3;
        case '4': return KEY_4;
        case '5': return KEY_5;
        case '6': return KEY_6;
        case '7': return KEY_7;
        case '8': return KEY_8;
        case '9': return KEY_9;
        case '0': return KEY_0;
        case '\r': case '\n': return KEY_ENTER;
        case '\t': return KEY_TAB;
        case ' ': return KEY_SPACE;
        case '-': return KEY_MINUS;
        case '=': return KEY_EQUAL;
        case '(': return KEY_LEFTBRACE;
        case ')': return KEY_RIGHTBRACE;
        case '\\': return KEY_BACKSLASH;
        case '~': return KEY_HASHTILDE;
        case ';': return KEY_SEMICOLON;
        case '\'': return KEY_APOSTROPHE;
        case '`': return KEY_GRAVE;
        case ',': return KEY_COMMA;
        case '.': return KEY_DOT;
        case '/': return KEY_SLASH;
        case '!': return KEY_1;
        case '@': return KEY_2;
        case '#': return KEY_3;
        case '$': return KEY_4;
        case '%': return KEY_5;
        case '^': return KEY_6;
        case '&': return KEY_7;
        case '*': return KEY_8;
        default: return KEY_HASHTILDE;
    }
}

uint8_t CharModifierKeys(char c)
{
    if (isalpha(c) && toupper(c) == c)
    {
        return KEY_MOD_LSHIFT;
    }

    switch (c)
    {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
            return KEY_MOD_LSHIFT;
        default:
            return KEY_MOD_NONE;
    }
}

uint8_t GetKeyContent(uint8_t key, char* buffer)
{
    char* MacroBuffer = buffer;

    switch (key)
    {
        case KEY_MACRO_0:
            return MACRO_KEY_0;
        case KEY_MACRO_1:
            return MACRO_KEY_1;
        case KEY_MACRO_2:
            return MACRO_KEY_2;
        case KEY_MACRO_3:
            return MACRO_KEY_3;
        case KEY_MACRO_4:
            return MACRO_KEY_4;
        case KEY_MACRO_5:
            return MACRO_KEY_5;
        case KEY_MACRO_6:
            return MACRO_KEY_6;
        case KEY_MACRO_7:
            return MACRO_KEY_7;
        case KEY_MACRO_8:
            return MACRO_KEY_8;
        case KEY_MACRO_9:
            return MACRO_KEY_9;
        case KEY_MACRO_10:
            return MACRO_KEY_10;
        case KEY_MACRO_11:
            return MACRO_KEY_11;
        case KEY_MACRO_12:
            return MACRO_KEY_12;
        case KEY_MACRO_13:
            return MACRO_KEY_13;
        case KEY_MACRO_14:
            return MACRO_KEY_14;
        case KEY_MACRO_15:
            return MACRO_KEY_15;
        case KEY_MACRO_16:
            return MACRO_KEY_16;
        case KEY_MACRO_17:
            return MACRO_KEY_17;
        case KEY_MACRO_18:
            return MACRO_KEY_18;
        case KEY_MACRO_19:
            return MACRO_KEY_19;
        default:
            return 0;
    }
}