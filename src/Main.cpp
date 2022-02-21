// clang-format off
#include "Application.h"
#include <iostream>
// clang-format on

int main()
{
    auto& app = Engine::Application::instance();
    app.run();

    return 0;
}
