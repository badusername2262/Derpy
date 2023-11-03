#include "../../Pch.h"
#include "WindowsWindow.h"

#include "../Events/WindowEvent.h"
#include "../Events/EngineEvent.h"
#include "../Events/KeyboardEvent.h"
#include "../Events/MouseEvent.h"

#include "../Events/KeyboardInputMacros.h"

namespace DERPY {

	static void GLFWErrorCallback(int error, const char* description)
	{
		std::stringstream ss;
		ss << "glfw error: " << error << "Discription: " << description;
		LOG_ERROR_VAR(ss.str());
	}

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

		ASSERT(glfwInit(), "GLFW Not Initalized");

        LOG_INFO("GLFW Initialized!");

        pWindow = glfwCreateWindow((int)Properties.Width, (int)Properties.Height, pTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(pWindow);
		glfwSetWindowUserPointer(pWindow, this);
        SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(pWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

			if (winPtr) {
			    WindowsWindow& win = *winPtr;
			    win.pWidth = width;
			    win.pHeight = height;
			} 
			else
			{
				ASSERT(winPtr, "winPtr is NULL!");
			}

			WindowResizeEvent event(width, height);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetWindowCloseCallback(pWindow, [](GLFWwindow* window)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetKeyCallback(pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(Derpy_Macros::ConvertFromGLFWToDERPY(key), 0);
					EventDispatcher::DispatchEvent(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(Derpy_Macros::ConvertFromGLFWToDERPY(key));
					EventDispatcher::DispatchEvent(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(Derpy_Macros::ConvertFromGLFWToDERPY(key), 1);
					EventDispatcher::DispatchEvent(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(pWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

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

		glfwSetScrollCallback(pWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetCursorPosCallback(pWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowsWindow* winPtr = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

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