#include "../Pch.h"
#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Events/EngineEvent.h"

#include <GLFW/glfw3.h>

namespace DERPY {

    bool pRunning = true;

    Engine::Engine(){
        pWindow = Window::Create();
        EventDispatcher::AddHandler(EventType::WindowResised, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::WindowClose, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseMoved, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseScrolled, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseButtonPressed, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseButtonReleased, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::KeyPressed, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::KeyReleased, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
    }
    
    Engine::~Engine(){

    }

    void Engine::OnEvent(Event& event)
    {
        if (event.IsHandled())
        {
            LOG_INFO("Event Has Already Been Handled.");
            return;
        }

        EventType eventType = event.GetEventType();

        switch (eventType) {
            case EventType::WindowResised :
            {
                const WindowResizeEvent& ResiseEvent = static_cast<const WindowResizeEvent&>(event);
                LOG_INFO_VAR(ResiseEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::WindowClose :
            {
                const WindowCloseEvent& CloseEvent = static_cast<const WindowCloseEvent&>(event);
                LOG_INFO_VAR(CloseEvent.ToString());
                pRunning = false;
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::MouseMoved :
            {
                const MouseMovedEvent& MouseMoveEvent = static_cast<const MouseMovedEvent&>(event);
                LOG_INFO_VAR(MouseMoveEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::MouseScrolled :
            {
                const MouseScrolledEvent& MouseScrollEvent = static_cast<const MouseScrolledEvent&>(event);
                LOG_INFO_VAR(MouseScrollEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::MouseButtonPressed :
            {
                const MouseButtonPressedEvent& MousebuttonPressEvent = static_cast<const MouseButtonPressedEvent&>(event);
                LOG_INFO_VAR(MousebuttonPressEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::MouseButtonReleased :
            {
                const MouseButtonReleasedEvent& MousebuttonReleaseEvent = static_cast<const MouseButtonReleasedEvent&>(event);
                LOG_INFO_VAR(MousebuttonReleaseEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::KeyPressed :
            {
                const KeyPressedEvent& KeyPressEvent = static_cast<const KeyPressedEvent&>(event);
                LOG_INFO_VAR(KeyPressEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
            case EventType::KeyReleased :
            {
                const KeyReleasedEvent& KeyReleaseEvent = static_cast<const KeyReleasedEvent&>(event);
                LOG_INFO_VAR(KeyReleaseEvent.ToString());
                const_cast<Event&>(event).SetHandled(true);
                break;
            }
        }
    }

    void Engine::Run(){
        LOG_INFO("Hello Derpy Is Running!");

        while(pRunning)
        {
            glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			pWindow->OnUpdate();
        }
    }

}