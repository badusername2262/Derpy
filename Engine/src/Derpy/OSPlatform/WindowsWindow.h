#include "../Window.h"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace DERPY 
{
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
        void InitVulkan();
        void InitGLFW();

        void CreateInstance();
        
        void Shutdown();

        std::string ToString() 
        {
            std::stringstream ss;
			ss << "Title: " << pTitle << ", Width: " << pWidth << ", Height: " << pHeight;
			return ss.str();
        }

    private:
        GLFWwindow* pWindow;
        VkInstance pInstance;

        bool pVSync;
        unsigned int pWidth, pHeight;
        std::string pTitle;
        EventCallback pEventCallBack;
    };
}