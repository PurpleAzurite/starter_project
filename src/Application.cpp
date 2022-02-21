#include "Application.h"

#define BIT(x) std::bind(&Engine::Application::x, this, std::placeholders::_1)

namespace Engine {

Application::Application()
    : m_mainWindow(new Window({1280, 720, "Starter Project"}))
{
}

Application::~Application()
{
    delete m_mainWindow;
}

Application& Application::instance()
{
    static Application singleton;
    return singleton;
}

void Application::run()
{
    while (m_running)
    {
        m_mainWindow->update();
    }
}

}
