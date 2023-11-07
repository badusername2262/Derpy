#include "Derpy.h"

class test : public DERPY::Layer
{
public:
    test()
        : Layer("test")
    {
    }

    void OnUpdate() override
    {
        LOG_INFO("haha");
    }

    void OnEvent(DERPY::Event& event) override
    {
        LOG_INFO_VAR(event.GetName());
    }
};

int main()
{
    DERPY::Engine app;

    app.AddLayer(new test());

//  Always have app.Run() at end of int main()
    app.Run();
    return 0;
}