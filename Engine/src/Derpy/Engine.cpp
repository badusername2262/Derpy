#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Logging/Logging.h"

namespace DERPY {

    Engine::Engine(){

    }
    
    Engine::~Engine(){

    }

    void HandleEvent(const Event& event) {
        EventType eventType = event.GetEventType();

        switch (eventType) {
            case EventType::WindowResised :
                const WindowResizeEvent& resiseevent = static_cast<const WindowResizeEvent&>(event);
                LOG_INFO_VAR("Handled Resize Event:", resiseevent.ToString());
                break;
        }
    }

    void Engine::Run(){
        LOG_INFO("Hello Derpy Is Running!");

        EventDispatcher::AddHandler(EventType::WindowResised, HandleEvent);

        WindowResizeEvent e(1920, 1080);

        EventDispatcher::DispatchEvent(e);

        system("pause");
    }

}
