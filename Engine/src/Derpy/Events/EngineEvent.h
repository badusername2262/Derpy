#pragma once

#include "Event.h"

namespace DERPY {

    class DERPY_API EngineTickEvent : public Event
    {
    public:
        EngineTickEvent() {}

        CLASS_TYPE_EVENT(EngineTick);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };

    class DERPY_API EngineUpdateEvent : public Event
    {
    public:
        EngineUpdateEvent() {}

        CLASS_TYPE_EVENT(EngineUpdate);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };

    class DERPY_API EngineRenderEvent : public Event
    {
    public:
        EngineRenderEvent() {}

        CLASS_TYPE_EVENT(EngineRender);
        CLASS_CATEGORY_EVENT(EngineEvent);
    };
}