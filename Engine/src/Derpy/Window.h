#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace DERPY
{
    struct WindowProperties
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProperties(const std::string& title = "Derpy Engine", unsigned int width = 1280, unsigned height = 720)
            :   Title(title), Width(width), Height(height)
        {

        }

        
    };
}