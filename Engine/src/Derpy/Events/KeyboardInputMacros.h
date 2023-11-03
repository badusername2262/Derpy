#pragma once

#include "../Core.h"
#include <GLFW/glfw3.h>

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

#define DERPY_KEY_LAST               DERPY_KEY_MENU

namespace DERPY 
{
    class DERPY_API Derpy_Macros
    {
    public:
        static int ConvertFromGLFWToDERPY(int Key) 
        {
            switch(Key) {
                // Special Keys
                case GLFW_KEY_SPACE : return DERPY_KEY_SPACE;
                case GLFW_KEY_APOSTROPHE : return DERPY_KEY_APOSTROPHE;
                case GLFW_KEY_COMMA : return DERPY_KEY_COMMA;
                case GLFW_KEY_MINUS : return DERPY_KEY_MINUS;
                case GLFW_KEY_PERIOD : return DERPY_KEY_PERIOD;
                case GLFW_KEY_SLASH : return DERPY_KEY_SLASH;
                case GLFW_KEY_SEMICOLON : return DERPY_KEY_SEMICOLON;
                case GLFW_KEY_EQUAL : return DERPY_KEY_EQUAL;
                case GLFW_KEY_LEFT_BRACKET : return DERPY_KEY_LEFT_BRACKET;
                case GLFW_KEY_BACKSLASH : return DERPY_KEY_BACKSLASH;
                case GLFW_KEY_RIGHT_BRACKET : return DERPY_KEY_RIGHT_BRACKET;
                case GLFW_KEY_GRAVE_ACCENT : return DERPY_KEY_GRAVE_ACCENT;
                case GLFW_KEY_WORLD_1 : return DERPY_KEY_WORLD_1;
                case GLFW_KEY_WORLD_2 : return DERPY_KEY_WORLD_2;

                // Normal Keys
                case GLFW_KEY_0 : return DERPY_KEY_0;
                case GLFW_KEY_1 : return DERPY_KEY_1;
                case GLFW_KEY_2 : return DERPY_KEY_2;
                case GLFW_KEY_3 : return DERPY_KEY_3;
                case GLFW_KEY_4 : return DERPY_KEY_4;
                case GLFW_KEY_5 : return DERPY_KEY_5;
                case GLFW_KEY_6 : return DERPY_KEY_6;
                case GLFW_KEY_7 : return DERPY_KEY_7;
                case GLFW_KEY_8 : return DERPY_KEY_8;
                case GLFW_KEY_9 : return DERPY_KEY_9;
                case GLFW_KEY_A : return DERPY_KEY_A;
                case GLFW_KEY_B : return DERPY_KEY_B;
                case GLFW_KEY_C : return DERPY_KEY_C;
                case GLFW_KEY_D : return DERPY_KEY_D;
                case GLFW_KEY_E : return DERPY_KEY_E;
                case GLFW_KEY_F : return DERPY_KEY_F;
                case GLFW_KEY_G : return DERPY_KEY_G;
                case GLFW_KEY_H : return DERPY_KEY_H;
                case GLFW_KEY_I : return DERPY_KEY_I;
                case GLFW_KEY_J : return DERPY_KEY_J;
                case GLFW_KEY_K : return DERPY_KEY_K;
                case GLFW_KEY_L : return DERPY_KEY_L;
                case GLFW_KEY_M : return DERPY_KEY_M;
                case GLFW_KEY_N : return DERPY_KEY_N;
                case GLFW_KEY_O : return DERPY_KEY_O;
                case GLFW_KEY_P : return DERPY_KEY_P;
                case GLFW_KEY_Q : return DERPY_KEY_Q;
                case GLFW_KEY_R : return DERPY_KEY_R;
                case GLFW_KEY_S : return DERPY_KEY_S;
                case GLFW_KEY_T : return DERPY_KEY_T;
                case GLFW_KEY_U : return DERPY_KEY_U;
                case GLFW_KEY_V : return DERPY_KEY_V;
                case GLFW_KEY_W : return DERPY_KEY_W;
                case GLFW_KEY_X : return DERPY_KEY_X;
                case GLFW_KEY_Y : return DERPY_KEY_Y;
                case GLFW_KEY_Z : return DERPY_KEY_Z;

                // Function Keys
                case GLFW_KEY_ESCAPE : return DERPY_KEY_ESCAPE;
                case GLFW_KEY_ENTER : return DERPY_KEY_ENTER;
                case GLFW_KEY_TAB : return DERPY_KEY_TAB;
                case GLFW_KEY_BACKSPACE : return DERPY_KEY_BACKSPACE;
                case GLFW_KEY_INSERT : return DERPY_KEY_INSERT;
                case GLFW_KEY_DELETE : return DERPY_KEY_DELETE;
                case GLFW_KEY_RIGHT : return DERPY_KEY_RIGHT;
                case GLFW_KEY_LEFT : return DERPY_KEY_LEFT;
                case GLFW_KEY_DOWN : return DERPY_KEY_DOWN;
                case GLFW_KEY_UP : return DERPY_KEY_UP;
                case GLFW_KEY_PAGE_UP : return DERPY_KEY_PAGE_UP;
                case GLFW_KEY_PAGE_DOWN : return DERPY_KEY_PAGE_DOWN;
                case GLFW_KEY_HOME : return DERPY_KEY_HOME;
                case GLFW_KEY_END : return DERPY_KEY_END;
                case GLFW_KEY_CAPS_LOCK : return DERPY_KEY_CAPS_LOCK;
                case GLFW_KEY_SCROLL_LOCK : return DERPY_KEY_SCROLL_LOCK;
                case GLFW_KEY_NUM_LOCK : return DERPY_KEY_NUM_LOCK;
                case GLFW_KEY_PRINT_SCREEN : return DERPY_KEY_PRINT_SCREEN;
                case GLFW_KEY_PAUSE : return DERPY_KEY_PAUSE;
                case GLFW_KEY_F1 : return DERPY_KEY_F1;
                case GLFW_KEY_F2 : return DERPY_KEY_F2;
                case GLFW_KEY_F3 : return DERPY_KEY_F3;
                case GLFW_KEY_F4 : return DERPY_KEY_F4;
                case GLFW_KEY_F5 : return DERPY_KEY_F5;
                case GLFW_KEY_F6 : return DERPY_KEY_F6;
                case GLFW_KEY_F7 : return DERPY_KEY_F7;
                case GLFW_KEY_F8 : return DERPY_KEY_F8;
                case GLFW_KEY_F9 : return DERPY_KEY_F9;
                case GLFW_KEY_F10 : return DERPY_KEY_F10;
                case GLFW_KEY_F11 : return DERPY_KEY_F11;
                case GLFW_KEY_F12 : return DERPY_KEY_F12;
                case GLFW_KEY_F13 : return DERPY_KEY_F13;
                case GLFW_KEY_F14 : return DERPY_KEY_F14;
                case GLFW_KEY_F15 : return DERPY_KEY_F15;
                case GLFW_KEY_F16 : return DERPY_KEY_F16;
                case GLFW_KEY_F17 : return DERPY_KEY_F17;
                case GLFW_KEY_F18 : return DERPY_KEY_F18;
                case GLFW_KEY_F19 : return DERPY_KEY_F19;
                case GLFW_KEY_F20 : return DERPY_KEY_F20;
                case GLFW_KEY_F21 : return DERPY_KEY_F21;
                case GLFW_KEY_F22 : return DERPY_KEY_F22;
                case GLFW_KEY_F23 : return DERPY_KEY_F23;
                case GLFW_KEY_F24 : return DERPY_KEY_F24;
                case GLFW_KEY_F25 : return DERPY_KEY_F25;
                case GLFW_KEY_KP_0 : return DERPY_KEY_KP_0;
                case GLFW_KEY_KP_1 : return DERPY_KEY_KP_1;
                case GLFW_KEY_KP_2 : return DERPY_KEY_KP_2;
                case GLFW_KEY_KP_3 : return DERPY_KEY_KP_3;
                case GLFW_KEY_KP_4 : return DERPY_KEY_KP_4;
                case GLFW_KEY_KP_5 : return DERPY_KEY_KP_5;
                case GLFW_KEY_KP_6 : return DERPY_KEY_KP_6;
                case GLFW_KEY_KP_7 : return DERPY_KEY_KP_7;
                case GLFW_KEY_KP_8 : return DERPY_KEY_KP_8;
                case GLFW_KEY_KP_9 : return DERPY_KEY_KP_9;
                case GLFW_KEY_KP_DECIMAL : return DERPY_KEY_KP_DECIMAL;
                case GLFW_KEY_KP_DIVIDE : return DERPY_KEY_KP_DIVIDE;
                case GLFW_KEY_KP_MULTIPLY : return DERPY_KEY_KP_MULTIPLY;
                case GLFW_KEY_KP_SUBTRACT : return DERPY_KEY_KP_SUBTRACT;
                case GLFW_KEY_KP_ADD : return DERPY_KEY_KP_ADD;
                case GLFW_KEY_KP_ENTER : return DERPY_KEY_KP_ENTER;
                case GLFW_KEY_KP_EQUAL : return DERPY_KEY_KP_EQUAL;
                case GLFW_KEY_LEFT_SHIFT : return DERPY_KEY_LEFT_SHIFT;
                case GLFW_KEY_LEFT_CONTROL : return DERPY_KEY_LEFT_CONTROL;
                case GLFW_KEY_LEFT_ALT : return DERPY_KEY_LEFT_ALT;
                case GLFW_KEY_LEFT_SUPER : return DERPY_KEY_LEFT_SUPER;
                case GLFW_KEY_RIGHT_SHIFT : return DERPY_KEY_RIGHT_SHIFT;
                case GLFW_KEY_RIGHT_CONTROL : return DERPY_KEY_RIGHT_CONTROL;
                case GLFW_KEY_RIGHT_ALT : return DERPY_KEY_RIGHT_ALT;
                case GLFW_KEY_RIGHT_SUPER : return DERPY_KEY_RIGHT_SUPER;
                case GLFW_KEY_MENU : return DERPY_KEY_MENU;

                default : return DERPY_KEY_UNKNOWN;
            }
        }
    };
}