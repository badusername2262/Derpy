#pragma once

#ifdef DRPY_PLATFORM_WINDOWS
    #ifdef DRPY_BUILD_DLL
        #define DRPY_API __declspec(dllexport)
    #else
        #define DRPY_API __declspec(dllimport)
    #endif
#endif