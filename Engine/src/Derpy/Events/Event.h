#pragma once

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

}