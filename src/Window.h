#pragma once

// clang-format off
#include "Events/Event.h"
#include "GLFW/glfw3.h"
#include <functional>
#include <string_view>
// clang-format on

namespace Engine {

class Window
{
    using CallbackFn = std::function<void(Event&)>;

private:
    struct WindowProps
    {
    public:
        int width;
        int height;
        std::string_view title;
        CallbackFn callback;
    };

public:
    Window(WindowProps data);
    ~Window();

public:
    void update();
    void setCallbackFunction(const CallbackFn& fn);

private:
    GLFWwindow* m_context;
    WindowProps m_data;
};

} // namespace Engine
