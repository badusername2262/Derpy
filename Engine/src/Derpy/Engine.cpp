#include "../Pch.h"
#include "Engine.h"

namespace DERPY {

    Engine::Engine(){
        pWindow = Window::Create();
        EventDispatcher::AddHandler(EventType::WindowResised, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::WindowClose, std::bind(&Engine::OnWindowClose, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseMoved, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseScrolled, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseButtonPressed, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::MouseButtonReleased, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::KeyPressed, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::KeyReleased, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        EventDispatcher::AddHandler(EventType::KeyRepeated, std::bind(&Engine::OnEvent, this, std::placeholders::_1));
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

        switch (eventType) 
        {
            case EventType::WindowResised :
            {
                WindowResizeEvent& ResiseEvent = static_cast<WindowResizeEvent&>(event);
                LOG_INFO_VAR(ResiseEvent.ToString());
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
                MouseButtonPressedEvent& MousebuttonPressEvent = static_cast<MouseButtonPressedEvent&>(event);
                LOG_INFO_VAR(MousebuttonPressEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::MouseButtonReleased :
            {
                MouseButtonReleasedEvent& MousebuttonReleaseEvent = static_cast<MouseButtonReleasedEvent&>(event);
                LOG_INFO_VAR(MousebuttonReleaseEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::KeyPressed :
            {
                KeyPressedEvent& KeyPressEvent = static_cast<KeyPressedEvent&>(event);
                Engine::pKey = KeyPressEvent.GetKeyCode();
                LOG_INFO_VAR(KeyPressEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::KeyReleased :
            {
                KeyReleasedEvent& KeyReleaseEvent = static_cast<KeyReleasedEvent&>(event);
                LOG_INFO_VAR(KeyReleaseEvent.ToString());
                event.SetHandled(true);
                break;
            }
            case EventType::KeyRepeated :
            {
                KeyRepeatedEvent& KeyRepeatEvent = static_cast<KeyRepeatedEvent&>(event);
                LOG_INFO_VAR(KeyRepeatEvent.ToString());
                event.SetHandled(true);
                break;
            }
        }

        for (auto it = pLayerStack.end(); it != pLayerStack.begin(); )
        {
            (*--it)->OnEvent(event);
            if (event.IsHandled())
                break;
        }
    }

    void Engine::OnWindowClose(Event& event)
    {

        if (event.IsHandled())
        {
            LOG_INFO("Event Has Already Been Handled.");
            return;
        }

        EventType eventType = event.GetEventType();

        switch(eventType)
        {
            case EventType::WindowClose :
            {
                WindowCloseEvent& CloseEvent = static_cast<WindowCloseEvent&>(event);
                LOG_INFO_VAR(CloseEvent.ToString());
                pRunning = false;
                event.SetHandled(true);
            }
        }
    }

    int Engine::OnKeyPress()
    {
        return Engine::pKey;
    }

    void Engine::AddLayer(Layer* layer)
    {
        pLayerStack.PushLayer(layer);
    }

    void Engine::AddOverlay(Layer* overlay)
    {
        pLayerStack.PushOverlay(overlay);
    }

    void Engine::Run()
    {
        while(pRunning)
        {
            for(Layer* layer : pLayerStack)
                layer->OnUpdate();
            
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            pWindow->OnUpdate();
        }
    }

}