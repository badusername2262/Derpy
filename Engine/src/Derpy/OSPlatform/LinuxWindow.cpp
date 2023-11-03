#include "../../Pch.h"
#include "LinuxWindow.h"

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
        return new LinuxWindow(Properties);
    }

    LinuxWindow::LinuxWindow(const WindowProperties& Properties)
    {
        Init(Properties);
    }

    LinuxWindow::~LinuxWindow()
    {
        Shutdown();
    }

    void LinuxWindow::Init(const WindowProperties& Properties)
    {
        pTitle = Properties.Title;
        pWidth = Properties.Width;
        pHeight = Properties.Height;

        LOG_INFO_VAR(LinuxWindow::ToString());

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
		glfwSetWindowUserPointer(pWindow, this);
        SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(pWindow, [](GLFWwindow* window, int width, int height)
		{
			LinuxWindow& win = *(LinuxWindow*)(glfwGetWindowUserPointer(window));
			win.pWidth = width;
			win.pHeight = height;

			WindowResizeEvent event(width, height);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetWindowCloseCallback(pWindow, [](GLFWwindow* window)
		{
			LinuxWindow& win = *(LinuxWindow*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetKeyCallback(pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			LinuxWindow& win = *(LinuxWindow*)glfwGetWindowUserPointer(window);

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
			LinuxWindow& win = *(LinuxWindow*)glfwGetWindowUserPointer(window);

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
			LinuxWindow& win = *(LinuxWindow*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetCursorPosCallback(pWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			LinuxWindow& win = *(LinuxWindow*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			EventDispatcher::DispatchEvent(event);
		});
    }

    void LinuxWindow::Shutdown()
    {
        LOG_INFO("Shutting Down.");
        glfwDestroyWindow(pWindow);
        glfwTerminate();
    }

    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(pWindow);
    }

    void LinuxWindow::SetVSync(bool Enabled)
    {
        if(Enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        
        pVSync = Enabled;
    }

    bool LinuxWindow::GetVSync() const
    {
        return pVSync;
    }
}