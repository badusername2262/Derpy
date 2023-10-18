#pragma once

#include "core.h"
#include "pthread.h"
#include <iostream>

namespace DERPY {

    class DRPY_API Engine
    {
    public:
        Engine();
        ~Engine();

        void Run();
    };
}
