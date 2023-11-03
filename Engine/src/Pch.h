#pragma once

#include <sstream>
#include <functional>
#include <sstream>
#include <iostream>
#include <chrono>
#include <memory>

#include "../external/GLFW/include/GLFW/glfw3.h"

#ifdef DRPY_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

#include "Derpy/logging/Logging.h"