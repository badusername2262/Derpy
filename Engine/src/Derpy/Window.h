#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "../../external/GLFW/include/GLFW/glfw3.h"

namespace DERPY {
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

        virtual void SetEventCallback(const EventCallback& callback) = 0;

        static Window* Create(const WindowProperties& Properties = WindowProperties());
    };

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& Properties);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return pWidth; }
        unsigned int GetHeight() const override { return pHeight; }
            
        void SetEventCallback(const EventCallback& callback) override { pEventCallBack = callback; }

        void SetVSync(bool Enabled) override;
        bool GetVSync() const override;

    private:
        void Init(const WindowProperties& Properties);
        void Shutdown();

        std::string ToString() 
        {
            std::stringstream ss;
			ss << "Title: " << pTitle << ", Width: " << pWidth << ", Height: " << pHeight;
			return ss.str();
        }

    private:
        GLFWwindow* pWindow;

        bool pVSync;
        unsigned int pWidth, pHeight;
        std::string pTitle;
        EventCallback pEventCallBack;
    };
}