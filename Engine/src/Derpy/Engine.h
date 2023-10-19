#pragma once

#include "core.h"
#include "Logging/Logging.h"

namespace DERPY {

    class DRPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
    };
}
