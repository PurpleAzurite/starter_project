#pragma once

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
};

} // namespace Engine
