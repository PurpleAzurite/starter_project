#include "Application.h"

namespace Engine {

Application::Application()
{
}

Application::~Application()
{
}

Application& Application::instance()
{
    static Application singleton;
    return singleton;
}

void Application::run()
{
    while (m_running)
        ;
}

}
