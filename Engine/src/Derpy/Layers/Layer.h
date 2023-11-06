#pragma once

#include "../Core.h"
#include "../Events/Event.h"

namespace DERPY
{
    class DERPY_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void AddLayer() {}
        virtual void RemoveLayer() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return pName; }
    private:
        std::string pName;
    };
}