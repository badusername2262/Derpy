#pragma once

#include "Event.h"

namespace DERPY {

    class DERPY_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return pKeyCode; }

        CLASS_CATEGORY_EVENT(KeyboardEvent | InputEvent);
    protected:
        KeyEvent(int keycode)
            :   pKeyCode(keycode) {}

        int pKeyCode;
    };

    class DERPY_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int KeyCode)
            :   KeyEvent(KeyCode){}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Keyboard Key Pressed Event: " << pKeyCode;
			return ss.str();
		}
    
        CLASS_TYPE_EVENT(KeyPressed);
    };

    class DERPY_API KeyRepeatedEvent : public KeyEvent
    {
    public:
        KeyRepeatedEvent(int KeyCode, int RepeatCount)
            :   KeyEvent(KeyCode), pRepeatCount(RepeatCount) {}

        inline int GetRepeatCount() const { return pRepeatCount; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Keyboard Key Repeated Event: " << pKeyCode << " (" << pRepeatCount << " RepeatCount)";
			return ss.str();
		}

        CLASS_TYPE_EVENT(KeyRepeated);
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