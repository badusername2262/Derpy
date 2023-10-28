#include "../Pch.h"
#include "Window.h"

namespace DERPY
{

    Window* Window::Create(const WindowProperties& Properties)
    {
        return new WindowsWindow(Properties);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& Properties)
    {
        Init(Properties);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProperties& Properties)
    {
        pTitle = Properties.Title;
        pWidth = Properties.Width;
        pHeight = Properties.Height;

        LOG_INFO_VAR("Window Properties:", WindowsWindow::ToString());

        if (!glfwInit())
        {
            LOG_WARNING("GLFW Not Initialized!");
        }
        else
        {
            LOG_INFO("GLFW Initialized!");
        }

        pWindow = glfwCreateWindow((int)Properties.Width, (int)Properties.Height, pTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(pWindow);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwTerminate();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(pWindow);
    }

    void WindowsWindow::SetVSync(bool Enabled)
    {
        if(Enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        
        pVSync = Enabled;
    }

    bool WindowsWindow::GetVSync() const
    {
        return pVSync;
    }
}