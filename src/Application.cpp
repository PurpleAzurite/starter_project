#include "Application.h"
#include "Events/WindowEvents.h"

#define BIND(x) std::bind(&Engine::Application::x, this, std::placeholders::_1)

namespace Engine {

Application::Application()
    : m_mainWindow(new Window({1280, 720, "Starter Project"}))
    , m_imgui(new ImGuiLayer{})
{
    m_mainWindow->setCallbackFunction(BIND(onEvent));
}

Application::~Application()
{
    delete m_imgui;
    delete m_mainWindow;
}

Application& Application::instance()
{
    static Application singleton;
    return singleton;
}

void Application::run()
{
    m_imgui->onAttach();

    while (m_running)
    {
        m_imgui->onUpdate();
        m_mainWindow->update();
    }

    m_imgui->onDetach();
}

void Application::onEvent(Event& event)
{
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowClosedEvent>(BIND(onWindowClosedEvent));
    event.log();
}

bool Application::onWindowClosedEvent(Event& event)
{
    m_running = false;
    return true;
}

} // namespace Engine
