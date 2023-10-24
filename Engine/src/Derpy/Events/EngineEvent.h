#pragma once

#include "Event.h"

namespace DERPY
{

    class DERPY_API EngineTickEvent : public Event
    {
        EngineTickEvent() {}

        CLASS_TYPE_EVENT(EngineTick);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };

    class DERPY_API EngineUpdateEvent : public Event
    {
        EngineUpdateEvent() {}

        CLASS_TYPE_EVENT(EngineUpdate);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };

    class DERPY_API EngineRenderEvent : public Event
    {
        EngineRenderEvent() {}

        CLASS_TYPE_EVENT(EngineRender);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };
}