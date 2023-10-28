#pragma once

#include "Event.h"

#include <sstream>

namespace DERPY
{

    class DERPY_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            :   pWidth(width), pHeight(height) {}

        inline unsigned int GetWidth() const { return pWidth; }
		inline unsigned int GetHeight() const { return pHeight; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event: " << pWidth << ", " << pHeight;
			return ss.str();
		}

        CLASS_TYPE_EVENT(WindowResised);
        CLASS_CATEGORY_EVENT(WindowEvent);
    private:
        unsigned int pWidth, pHeight;
    };

    class DERPY_API WindowCloseEvent : public Event
    {
        WindowCloseEvent() {}

        CLASS_TYPE_EVENT(WindowClose);
        CLASS_CATEGORY_EVENT(WindowEvent);
    };

    class DERPY_API WindowFocusEvent : public Event
    {
        WindowFocusEvent() {}

        CLASS_TYPE_EVENT(WindowFocus);
        CLASS_CATEGORY_EVENT(WindowEvent);
    };

    class DERPY_API WindowWindowLostFocuseEvent : public Event
    {
        WindowWindowLostFocuseEvent() {}

        CLASS_TYPE_EVENT(WindowLostFocuse);
        CLASS_CATEGORY_EVENT(WindowEvent);
    };

    class DERPY_API WindowMovedEvent : public Event
    {
        WindowMovedEvent() {}

        CLASS_TYPE_EVENT(WindowMoved);
        CLASS_CATEGORY_EVENT(WindowEvent);
    };

}