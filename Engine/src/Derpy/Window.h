#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace DERPY 
{

    struct WindowProperties
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProperties(const std::string& title = "Derpy Engine", unsigned int width = 1280, unsigned height = 720)
            :   Title(title), Width(width), Height(height)
        { }
    };

    class DERPY_API Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetVSync(bool Enabled) = 0;
        virtual bool GetVSync() const = 0;

        static Window* Create(const WindowProperties& Properties = WindowProperties());
    };
}