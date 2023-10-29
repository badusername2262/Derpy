#include "../Pch.h"
#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace DERPY {

    Engine::Engine(){
        pWindow = Window::Create();
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
                LOG_INFO_VAR(ResiseEvent.ToString());
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
            LOG_INFO("Window Event.");

        while(pRunning)
        {
            glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			pWindow->OnUpdate();
        }
    }

}
