#pragma once

#include "Event.h"

#include <sstream>

namespace DERPY
{

    class DERPY_API MouseMovedEvent : Event
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

    private:
        float pX, pY;
    };
}