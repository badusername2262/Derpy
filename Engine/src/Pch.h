#pragma once

#include <functional>
#include <sstream>
#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

#ifdef DRPY_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

#include "Derpy/Logging/Logging.h"