#include "../../Pch.h"
#include "LayerStack.h"

namespace DERPY
{

    LayerStack::LayerStack()
    {
        pLayerInsert = pLayers.begin();
    };

    LayerStack::~LayerStack()
    {
        for(Layer* layer : pLayers)
            delete layer;
    };

    void LayerStack::PushLayer(Layer* layer)
    {
        pLayerInsert = pLayers.emplace(pLayerInsert, layer);
    };

    void LayerStack::PushOverlay(Layer* overlay)
    {
        pLayers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(pLayers.begin(), pLayers.end(), layer);
        if (it != pLayers.end())
        {
            pLayers.erase(it);
            pLayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(pLayers.begin(), pLayers.end(), overlay);
        if (it != pLayers.end())
            pLayers.erase(it);
    }

}