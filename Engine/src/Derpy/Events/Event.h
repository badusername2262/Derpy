#pragma once

#include "../Core.h"

#include <string>
#include <functional>

namespace DERPY
{

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResised, WindowFocus, WindowLostFocuse, WindowMoved,
        EngineTick, EngineUpdate, EngineRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleasted, MouseMoved, MouseScrolled
    };

	class DERPY_API Event
    {
    public:
		virtual EventType GetEventType() const = 0;
	    virtual const char* GetName() const = 0;
    	virtual int GetCategoryFlags() const = 0;
    	virtual std::string ToString() const { return GetName(); }

    	inline bool IsInCategory(EventCategory category)
    	{
    		return GetCategoryFlags() & category;
    	}
	protected:
	    bool m_Handled = false;
    };
}