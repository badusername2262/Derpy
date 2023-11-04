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

		InitVulkan();
		InitGLFW();
        LOG_INFO_VAR(LinuxWindow::ToString());

    }

	void LinuxWindow::InitVulkan()
	{
		CreateInstance();
	}

	void LinuxWindow::CreateInstance()
	{
		VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = pTitle.c_str();
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Derpy Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_3;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;
    
        VkResult result = vkCreateInstance(&createInfo, nullptr, &pInstance);
    
        if (result != VK_SUCCESS) {
        	LOG_WARNING("No Vulkan Supported GPU Detected!");
			LOG_WARNING("Falling back to Opengl");
			IsVulkan = false;
        }

		if(IsVulkan)
		{

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    
        std::cout << "available extensions:\n";

        for (const auto& extension : extensions) {
            std::cout << '\t' << extension.extensionName << '\n';
        }

		}
	}

	void LinuxWindow::InitGLFW()
	{
		ASSERT(glfwInit(), "GLFW Not Initalized");

		if(IsVulkan)
		{
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		}

        LOG_INFO("GLFW Initialized!");

        pWindow = glfwCreateWindow((int)pWidth, (int)pHeight, pTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(pWindow);
		glfwSetWindowUserPointer(pWindow, this);
        SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(pWindow, [](GLFWwindow* window, int width, int height)
		{
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));

			if (winPtr) {
			    LinuxWindow& win = *winPtr;
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
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetKeyCallback(pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));

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
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));

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
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			EventDispatcher::DispatchEvent(event);
		});

		glfwSetCursorPosCallback(pWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			LinuxWindow* winPtr = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));

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