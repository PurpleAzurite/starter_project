#pragma once

// clang-format off
#include "Window.h"
#include "Layers/ImGuiLayer.h"
#include "Layers/LayerStack.h"
// clang-format on

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
    inline void close() { m_running = false; }

private:
    bool m_running = true;
    double m_frameTime = 0;

    Window* m_mainWindow;
    ImGuiLayer* m_imgui;
    LayerStack m_layers;
};

} // namespace Engine
