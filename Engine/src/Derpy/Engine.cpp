#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Logging/Logging.h"

namespace DERPY {

    Engine::Engine(){

    }
    
    Engine::~Engine(){

    }

    void HandleEvent(const Event& event)
    {
        if (event.IsHandled())
        {
            LOG_INFO("Event Has Already Been Handled.");
            return;
        }

        EventType eventType = event.GetEventType();

        switch (eventType) {
            case EventType::WindowResised :
                const WindowResizeEvent& ResiseEvent = static_cast<const WindowResizeEvent&>(event);
                LOG_INFO_VAR("Handled Resize Event:", ResiseEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
        }
    }

    void Engine::Run(){
        LOG_INFO("Hello Derpy Is Running!");

        EventDispatcher::AddHandler(EventType::WindowResised, HandleEvent);

        WindowResizeEvent e(1920, 1080);

        EventDispatcher::DispatchEvent(e);

        if (e.IsInCategory(WindowEvent))
            LOG_INFO("YES.");

        system("pause");
    }

}
