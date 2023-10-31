#include "../Pch.h"
#include "Window.h"

namespace DERPY {

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

        LOG_INFO_VAR(WindowsWindow::ToString());

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

        
		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					EventDispatcher::DispatchEvent(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					EventDispatcher::DispatchEvent(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					EventDispatcher::DispatchEvent(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					EventDispatcher::DispatchEvent(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					EventDispatcher::DispatchEvent(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			EventDispatcher::DispatchEvent(event);
		});
    }

    void WindowsWindow::Shutdown()
    {
        LOG_INFO("Shutting Down.");
        glfwDestroyWindow(pWindow);
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