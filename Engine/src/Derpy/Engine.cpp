#include "../Pch.h"
#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Events/EngineEvent.h"

#include "Events/KeyboardInputMacros.h"

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
        pWindow->~Window();
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
                WindowResizeEvent& ResiseEvent = static_cast<WindowResizeEvent&>(event);
                LOG_INFO_VAR(ResiseEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::WindowClose :
            {
                WindowCloseEvent& CloseEvent = static_cast<WindowCloseEvent&>(event);
                LOG_INFO_VAR(CloseEvent.ToString());
                pRunning = false;
                event.SetHandled(true);
                break;
            }
            case EventType::MouseMoved :
            {
                MouseMovedEvent& MouseMoveEvent = static_cast<MouseMovedEvent&>(event);
                LOG_INFO_VAR(MouseMoveEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::MouseScrolled :
            {
                MouseScrolledEvent& MouseScrollEvent = static_cast<MouseScrolledEvent&>(event);
                LOG_INFO_VAR(MouseScrollEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::MouseButtonPressed :
            {
                const MouseButtonPressedEvent& MousebuttonPressEvent = static_cast<const MouseButtonPressedEvent&>(event);
                LOG_INFO_VAR(MousebuttonPressEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::MouseButtonReleased :
            {
                const MouseButtonReleasedEvent& MousebuttonReleaseEvent = static_cast<const MouseButtonReleasedEvent&>(event);
                LOG_INFO_VAR(MousebuttonReleaseEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::KeyPressed :
            {
                const KeyPressedEvent& KeyPressEvent = static_cast<const KeyPressedEvent&>(event);
                LOG_INFO_VAR(KeyPressEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::KeyReleased :
            {
                const KeyReleasedEvent& KeyReleaseEvent = static_cast<const KeyReleasedEvent&>(event);
                LOG_INFO_VAR(KeyReleaseEvent.ToString());
                event.SetHandled(true);
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