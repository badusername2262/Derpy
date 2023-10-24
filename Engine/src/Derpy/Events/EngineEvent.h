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
			ss << "WindowResizeEvent: " << pWidth << ", " << pHeight;
			return ss.str();
		}

        CLASS_TYPE_EVENT(WindowResised);
        CLASS_CATEGORY_EVENT(WindowEvent);
    private:
        unsigned int pWidth, pHeight;
    };


}