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

    enum CategoryEvents
    {
        None = 0,
        WindowEvent       = 1,
        InputEvent        = 2,
        KeyboardEvent     = 4,
        MouseMoveEvent    = 8,
        MouseButtonEvent  = 16
    };

    #define CLASS_TYPE_EVENT(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

    #define CLASS_CATEGORY_EVENT(category) virtual int GetCategoryFlags() const override { return category; }

	class DERPY_API Event
    {
    public:
		virtual EventType GetEventType() const = 0;
	    virtual const char* GetName() const = 0;
    	virtual int GetCategoryFlags() const = 0;
    	virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(CategoryEvents category)
        {
            return GetCategoryFlags() & category;
        }
	protected:
	    bool m_Handled = false;
    };
}