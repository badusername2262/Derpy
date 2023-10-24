#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace DERPY {

    class DERPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
    };
}
