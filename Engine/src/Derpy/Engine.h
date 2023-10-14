#pragma once

#include "core.h"

namespace DERPY {

    class DRPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
    };

    Engine* CreateWindow();

}
