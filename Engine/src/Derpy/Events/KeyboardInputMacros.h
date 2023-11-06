#pragma once

#include "../Core.h"

        // Unknown Key
#define DERPY_KEY_UNKNOWN           -1

        // Special Keys
#define DERPY_KEY_SPACE             110  /*   */
#define DERPY_KEY_APOSTROPHE        111  /* ' */
#define DERPY_KEY_COMMA             112  /* , */
#define DERPY_KEY_MINUS             113  /* - */
#define DERPY_KEY_PERIOD            114  /* . */
#define DERPY_KEY_SLASH             115  /* / */
#define DERPY_KEY_SEMICOLON         116  /* ; */
#define DERPY_KEY_EQUAL             117  /* = */
#define DERPY_KEY_LEFT_BRACKET      118  /* [ */
#define DERPY_KEY_BACKSLASH         119  /* \ */
#define DERPY_KEY_RIGHT_BRACKET     120  /* ] */
#define DERPY_KEY_GRAVE_ACCENT      121  /* ` */
#define DERPY_KEY_WORLD_1           122  /* non-US #1 */
#define DERPY_KEY_WORLD_2           123  /* non-US #2 */

        // Numbers And Letters
#define DERPY_KEY_0                  10
#define DERPY_KEY_1                  1
#define DERPY_KEY_2                  2
#define DERPY_KEY_3                  3
#define DERPY_KEY_4                  4
#define DERPY_KEY_5                  5
#define DERPY_KEY_6                  6
#define DERPY_KEY_7                  7
#define DERPY_KEY_8                  8
#define DERPY_KEY_9                  9
#define DERPY_KEY_A                  11
#define DERPY_KEY_B                  12
#define DERPY_KEY_C                  13
#define DERPY_KEY_D                  14
#define DERPY_KEY_E                  15
#define DERPY_KEY_F                  16
#define DERPY_KEY_G                  17
#define DERPY_KEY_H                  18
#define DERPY_KEY_I                  19
#define DERPY_KEY_J                  20
#define DERPY_KEY_K                  21
#define DERPY_KEY_L                  22
#define DERPY_KEY_M                  23
#define DERPY_KEY_N                  24
#define DERPY_KEY_O                  25
#define DERPY_KEY_P                  26
#define DERPY_KEY_Q                  27
#define DERPY_KEY_R                  28
#define DERPY_KEY_S                  29
#define DERPY_KEY_T                  30
#define DERPY_KEY_U                  31
#define DERPY_KEY_V                  32
#define DERPY_KEY_W                  33
#define DERPY_KEY_X                  34
#define DERPY_KEY_Y                  35
#define DERPY_KEY_Z                  36

        // Function keys
#define DERPY_KEY_ESCAPE             37
#define DERPY_KEY_ENTER              38
#define DERPY_KEY_TAB                39
#define DERPY_KEY_BACKSPACE          40
#define DERPY_KEY_INSERT             41
#define DERPY_KEY_DELETE             42
#define DERPY_KEY_RIGHT              43
#define DERPY_KEY_LEFT               44
#define DERPY_KEY_DOWN               45
#define DERPY_KEY_UP                 46
#define DERPY_KEY_PAGE_UP            47
#define DERPY_KEY_PAGE_DOWN          48
#define DERPY_KEY_HOME               49
#define DERPY_KEY_END                50
#define DERPY_KEY_CAPS_LOCK          51
#define DERPY_KEY_SCROLL_LOCK        52
#define DERPY_KEY_NUM_LOCK           53
#define DERPY_KEY_PRINT_SCREEN       54
#define DERPY_KEY_PAUSE              55
#define DERPY_KEY_F1                 56
#define DERPY_KEY_F2                 57
#define DERPY_KEY_F3                 58
#define DERPY_KEY_F4                 59
#define DERPY_KEY_F5                 60
#define DERPY_KEY_F6                 61
#define DERPY_KEY_F7                 62
#define DERPY_KEY_F8                 63
#define DERPY_KEY_F9                 64
#define DERPY_KEY_F10                65
#define DERPY_KEY_F11                66
#define DERPY_KEY_F12                67
#define DERPY_KEY_F13                68
#define DERPY_KEY_F14                69
#define DERPY_KEY_F15                70
#define DERPY_KEY_F16                71
#define DERPY_KEY_F17                72
#define DERPY_KEY_F18                73
#define DERPY_KEY_F19                74
#define DERPY_KEY_F20                75
#define DERPY_KEY_F21                76
#define DERPY_KEY_F22                77
#define DERPY_KEY_F23                78
#define DERPY_KEY_F24                79
#define DERPY_KEY_F25                80
#define DERPY_KEY_KP_0               81
#define DERPY_KEY_KP_1               82
#define DERPY_KEY_KP_2               83
#define DERPY_KEY_KP_3               84
#define DERPY_KEY_KP_4               85
#define DERPY_KEY_KP_5               86
#define DERPY_KEY_KP_6               87
#define DERPY_KEY_KP_7               88
#define DERPY_KEY_KP_8               89
#define DERPY_KEY_KP_9               90
#define DERPY_KEY_KP_DECIMAL         91
#define DERPY_KEY_KP_DIVIDE          92
#define DERPY_KEY_KP_MULTIPLY        93
#define DERPY_KEY_KP_SUBTRACT        94
#define DERPY_KEY_KP_ADD             95
#define DERPY_KEY_KP_ENTER           96
#define DERPY_KEY_KP_EQUAL           97
#define DERPY_KEY_LEFT_SHIFT         98
#define DERPY_KEY_LEFT_CONTROL       99
#define DERPY_KEY_LEFT_ALT           100
#define DERPY_KEY_LEFT_SUPER         101
#define DERPY_KEY_RIGHT_SHIFT        102
#define DERPY_KEY_RIGHT_CONTROL      103
#define DERPY_KEY_RIGHT_ALT          104
#define DERPY_KEY_RIGHT_SUPER        105
#define DERPY_KEY_MENU               106

#define DERPY_KEY_LAST               DERPY_KEY_WORLD_2

namespace DERPY 
{
    class DERPY_API Derpy_Macros
    {
    public:
        static int ConvertFromGLFWToDERPY(int Key);
    };
}