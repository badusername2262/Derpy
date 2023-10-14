#include "Derpy.h"

class App : public DERPY::Engine
{
public:
    App()
    {

    }

    ~App()
    {

    }
};

DERPY::Engine* DERPY::CreateWindow()
{
    return new App();
}