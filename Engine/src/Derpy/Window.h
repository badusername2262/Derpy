#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "../../external/GLFW/include/GLFW/glfw3.h"

namespace DERPY
{
    struct WindowProperties
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProperties(const std::string& title = "Derpy Engine", unsigned int width = 1280, unsigned height = 720)
            :   Title(title), Width(width), Height(height)
        {
            
        }
    };

    class DERPY_API Window
    {
        public:
            using EventCallback = std::function<void(Event&)>;

            ~Window() {}

            void OnUpdate();

            unsigned int GetWidth() const;
            unsigned int GetHeight() const;

            void SetEventCallback(const EventCallback& callback);
            void SetVSync(bool enabled);
            bool IsVSync() const;

            static Window* Create(const WindowProperties& Properties = WindowProperties());
    };
}