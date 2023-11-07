#include "../../Pch.h"
#include "KeyboardInputMacros.h"

#include <GLFW/glfw3.h>

namespace DERPY
{
    int Derpy_Macros::ConvertFromGLFWToDERPY(int Key)
    {
        switch(Key)
        {

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
}