#pragma once

#include "Core.h"

// Events ---------------------------------------
#include "Events/Event.h"
#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Events/EngineEvent.h"
#include "Events/KeyboardInputMacros.h"
// Events ---------------------------------------

#include "Layers/LayerStack.h"

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

        int OnKeyReleaseEvent(unsigned int DERPY_KEY_TYPE);
        int OnKeyRepeateEvent(unsigned int DERPY_KEY_TYPE);
        
        void OnEvent(Event& event);
    
        void AddLayer(Layer* layer);
        void AddOverlay(Layer* overlay);

    private:
        void OnWindowClose(Event& event);

        Window* pWindow;
        LayerStack pLayerStack;
        bool pRunning = true;
    };
}
