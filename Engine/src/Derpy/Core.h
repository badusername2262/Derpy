#pragma once

    #ifdef DRPY_BUILD_DLL
        #define DERPY_API __declspec(dllexport)
    #else
        #define DERPY_API __declspec(dllimport)
    #endif

#define BIT(x) (1 << x)