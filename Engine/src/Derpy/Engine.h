#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace DERPY {

    class DERPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();
    private:
        Window* pWindow;
        bool pRunning = true;
    };
}
