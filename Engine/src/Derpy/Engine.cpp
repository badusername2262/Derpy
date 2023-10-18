#include "Engine.h"

namespace DERPY {

    Engine::Engine(){

    }
    
    Engine::~Engine(){

    }

    void Engine::Run(){
        LOG_INFO("this is an info log!");
        LOG_WARNING("this is a warning log!");
        LOG_ERROR("this is an error log!");
        system("pause");
    }

}
