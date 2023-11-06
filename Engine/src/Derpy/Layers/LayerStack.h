#pragma once

#include "../Core.h"
#include "Layer.h"

namespace DERPY
{

    class DERPY_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin() { return pLayers.begin(); }
        std::vector<Layer*>::iterator end() { return pLayers.end(); }
    private:
        std::vector<Layer*> pLayers;
        std::vector<Layer*>::iterator pLayerInsert;
    };

}