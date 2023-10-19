#pragma once

#include "Core.h"
#include "Logging/Logging.h"

namespace DERPY {

    class DERPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
    };
}
