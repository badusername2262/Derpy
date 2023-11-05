#pragma once

#include "Core.h"
#include "Events/Event.h"

#ifdef DRPY_PLATFORM_WINDOWS
    #include "OSPlatform/WindowsWindow.h"
#elif DRPY_PLATFORM_LINUX
    #include "OSPlatform/LinuxWindow.h"
#endif

namespace DERPY {

    class DERPY_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void Run();

    private:
        void OnEvent(Event& event);

        Window* pWindow;
    };
}
