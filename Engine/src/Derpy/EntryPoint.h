#pragma once

#ifdef DRPY_PLATFORM_WINDOWS

extern DERPY::Engine* DERPY::CreateWindow();

int main(int argc, char** argv)
{
    
    std::cout << "Hello This Engine Is Called Derpy." << std::endl;
    auto app = DERPY::CreateWindow();
    app->Run();
    delete app;
}

#endif