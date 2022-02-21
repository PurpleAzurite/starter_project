#pragma once

#include "Window.h"

namespace Engine {

class Application
{
private:
    Application();
    ~Application();

public:
    static Application& instance();
    void run();

private:
    bool m_running = true;
    Window* m_mainWindow;
};

} // namespace Engine
