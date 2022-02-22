// clang-format off
#include "Application.h"
#include "Logging.h"
#include <iostream>
// clang-format on

int main()
{
    Engine::Logger::init();
    auto& app = Engine::Application::instance();
    app.run();

    return 0;
}
