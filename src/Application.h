#pragma once

#include "Window.h"
#include "Layers/ImGuiLayer.h"

namespace Engine {

class Application
{
private:
    Application();
    ~Application();

public:
    static Application& instance();
    void run();
    void onEvent(Event& event);
    bool onWindowClosedEvent(Event& event);

    inline Window* window() { return m_mainWindow; }

private:
    bool m_running = true;
    Window* m_mainWindow;
    ImGuiLayer* m_imgui;
};

} // namespace Engine
