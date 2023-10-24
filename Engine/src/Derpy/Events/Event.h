#pragma once

#include "../Core.h"

#include <string>
#include <functional>
#include <vector>

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

    #define CLASS_TYPE_EVENT(type) static EventType GetStaticType() { return EventType::type; }\
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
	    bool handled = false;
    };

    template <typename EventType>
    class EventDispatcher
    {
    public:
        EventDispatcher() {}
    
        void RegisterListener(std::function<void(EventType*)> listener)
        {
            m_listeners.push_back(listener);
        }
    
        void UnregisterListener(std::function<void(EventType*)> listener)
        {
            m_listeners.erase(std::remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());
        }
    
        bool DispatchEvent(EventType* event)
        {
            bool handled = false;
            for (auto& listener : m_listeners)
            {
                listener(event);
                handled = event->handled;
                if (handled)
                {
                    break;
                }
            }
            return handled;
        }
    
    private:
        std::vector<std::function<void(EventType*)>> m_listeners;
    };
}