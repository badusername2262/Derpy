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

        void OnEvent(Event& event);
    private:
        Window* pWindow;
    };
}
