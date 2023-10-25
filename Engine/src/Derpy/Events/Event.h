#pragma once

#include "../Core.h"

#include <functional>
#include <map>
#include <string>
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
        EngineEvent       = 2,
        InputEvent        = 4,
        KeyboardEvent     = 8,
        MouseMoveEvent    = 16,
        MouseButtonEvent  = 32
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

        inline bool IsHandled() const
        {
            return handled;
        }

        inline void SetHandled(bool IsHandled)
        {
            handled = IsHandled;
        }
        
	protected:
	    bool handled = false;
    };

    class DERPY_API EventDispatcher
    {
    public:
        using pEventHandler = std::function<void(Event&)>;

        static void AddHandler(EventType pEventType, pEventHandler peventHandler)
        {
            pEventHandlers[pEventType].push_back(peventHandler);    
        }
        
        static void DispatchEvent(Event& pEvent)
        {
            EventType pEventType = pEvent.GetEventType();

            if (pEventHandlers.find(pEventType) != pEventHandlers.end())
            {
                for (const auto& pHandler : pEventHandlers[pEventType])
                {
                    pHandler(pEvent);
                }
            }
        }

    
    private:
        inline static std::map<EventType, std::vector<pEventHandler>> pEventHandlers;
    };
}