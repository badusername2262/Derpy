#include "Derpy.h"

int main()
{

    DERPY::Engine* app = new DERPY::Engine;

    app->Run();

    delete app;
    return 0;
}