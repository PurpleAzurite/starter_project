#pragma once

// clang-format off
#include "Events/Event.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
    Window(WindowProps props);
    ~Window();

public:
    void update();
    void setCallbackFunction(const CallbackFn& fn);
    inline GLFWwindow* context() { return m_context; }

private:
    GLFWwindow* m_context;
    WindowProps m_data;
};

} // namespace Engine
