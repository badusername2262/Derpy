#include "Engine.h"

#include "Events/WindowEvent.h"
#include "Logging/Logging.h"

namespace DERPY {

    Engine::Engine(){

    }
    
    Engine::~Engine(){

    }

    void Engine::Run(){
        LOG_INFO("Hello Derpy Is Running!");

        WindowResizeEvent e(1920, 1080);
        if(e.IsInCategory(WindowEvent))
        {
            LOG_INFO_VAR("value", e.ToString());
        }

        system("pause");
    }

}
