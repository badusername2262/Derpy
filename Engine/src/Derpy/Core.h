#pragma once

#ifdef DRPY_PLATFORM_WINDOWS
    #ifdef DRPY_BUILD_DLL
        #define DERPY_API __declspec(dllexport)
    #else
        #define DERPY_API __declspec(dllimport)
    #endif
#elif DRPY_PLATFORM_LINUX
    #define DERPY_API __attribute__((visibility("default")))
#endif