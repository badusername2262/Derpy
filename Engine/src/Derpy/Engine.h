#pragma once

#include "core.h"
#include "logging/Logging.h"

namespace DERPY {

    class DRPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
        void Render();
        void Update();
    };
}
