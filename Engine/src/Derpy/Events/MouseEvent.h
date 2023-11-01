#pragma once

#include "Event.h"

namespace DERPY {

    class DERPY_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            :   pX(x), pY(y) {}

        inline float getX() const { return pX; }
        inline float getY() const { return pY; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved Event: " << pX << ", " << pY;
			return ss.str();
		}

        CLASS_TYPE_EVENT(MouseMoved);
        CLASS_CATEGORY_EVENT(MouseButtonEvent | InputEvent);
    private:
        float pX, pY;
    };

    class DERPY_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float Xoffset, float Yoffset)
            :   pXoffset(Xoffset), pYoffset(Yoffset) {}
        
        inline float GetXoffset() const { return pXoffset; }
        inline float GetYoffset() const { return pYoffset; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled Event: " << pXoffset << ", " << pYoffset;
			return ss.str();
		}

        CLASS_TYPE_EVENT(MouseScrolled);
        CLASS_CATEGORY_EVENT(MouseButtonEvent | InputEvent);
    private:
        float pXoffset, pYoffset;
    };

    class DERPY_API MouseButtonCallEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return pButton; }

        CLASS_CATEGORY_EVENT(MouseButtonEvent | InputEvent);
    protected:
        MouseButtonCallEvent(int Button)
            :   pButton(Button) {}

        int pButton;
    };

    class DERPY_API MouseButtonPressedEvent : public MouseButtonCallEvent
    {
    public:
        MouseButtonPressedEvent(int Button)
            :   MouseButtonCallEvent(Button) {}
    
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Buttton Pressed Event: " << pButton;
			return ss.str();
		}

        CLASS_TYPE_EVENT(MouseButtonPressed);
    };

    class DERPY_API MouseButtonReleasedEvent : public MouseButtonCallEvent
    {
    public:
        MouseButtonReleasedEvent(int Button)
            :   MouseButtonCallEvent(Button) {}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Buttton Released Event: " << pButton;
			return ss.str();
		}

        CLASS_TYPE_EVENT(MouseButtonReleased);
    };
}