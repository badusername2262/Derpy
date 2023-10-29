#pragma once

#include "Event.h"

namespace DERPY {

    class DERPY_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return pKeyCode; }

        CLASS_CATEGORY_EVENT(KeyboardEvent | InputEvent);
    protected:
        KeyEvent(int KeyCode)
            :   pKeyCode(KeyCode) {}

        int pKeyCode;
    };

    class DERPY_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int KeyCode, int RepeatCount)
            :   KeyEvent(KeyCode), pRepeatCount(RepeatCount) {}

        inline int GetRepeatCount() const { return pRepeatCount; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Keyboard Key Pressed Event: " << pKeyCode << " (" << pRepeatCount << " RepeatCount)";
			return ss.str();
		}
    
        CLASS_TYPE_EVENT(KeyPressed);
    private:
        int pRepeatCount;
    };

    class DERPY_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int KeyCode)
            :   KeyEvent(KeyCode) {}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Keyboard Key Released Event: " << pKeyCode;
			return ss.str();
		}
    
        CLASS_TYPE_EVENT(KeyReleased);
    };

}