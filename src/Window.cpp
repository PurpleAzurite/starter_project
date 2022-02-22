// clang-format off
#include "Window.h"
#include "Events/WindowEvents.h"
#include "Events/MouseEvents.h"
#include <utility>
// clang-format on

namespace Engine {

Window::Window(WindowProps data)
    : m_data(std::move(data))
{
    glfwSetErrorCallback(
        [](int code, const char* msg) { ENGINE_ERROR("[GLFW] Error {}: {}", code, msg); });

    glfwInit();

    m_context =
        glfwCreateWindow(m_data.width, m_data.height, m_data.title.data(), nullptr, nullptr);

    glfwMakeContextCurrent(m_context);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        ENGINE_ERROR("[GLAD] Could not load GLAD!");

    glfwSetWindowUserPointer(m_context, reinterpret_cast<void*>(&m_data));

    glfwSetWindowCloseCallback(m_context, [](GLFWwindow* window) {
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));
        WindowClosedEvent event;
        data.callback(event);
    });

    glfwSetWindowPosCallback(m_context, [](GLFWwindow* window, int x, int y) {
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));
        WindowMovedEvent event(x, y);
        data.callback(event);
    });

    glfwSetWindowSizeCallback(m_context, [](GLFWwindow* window, int width, int height) {
        // TODO: Should framebuffer be resized here?
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));
        WindowResizedEvent event(width, height);
        data.callback(event);
    });

    glfwSetWindowFocusCallback(m_context, [](GLFWwindow* window, int focus) {
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));

        switch (focus)
        {
        case 1: {
            WindowFocusedEvent event;
            data.callback(event);
            break;
        }
        case 0: {
            WindowLostFocusEvent event;
            data.callback(event);
            break;
        }
        }
    });

    glfwSetCursorPosCallback(m_context, [](GLFWwindow* window, double x, double y) {
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));
        MouseMovedEvent event(x, y);
        data.callback(event);
    });

    glfwSetMouseButtonCallback(m_context, [](GLFWwindow* window, int button, int action, int mods) {
        (void)mods;
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));

        switch (action)
        {
        case GLFW_PRESS: {
            MouseButtonPressedEvent event(button);
            data.callback(event);
            break;
        }

        case GLFW_RELEASE: {
            MouseButtonReleasedEvent event(button);
            data.callback(event);
            break;
        }
        }
    });

    glfwSetScrollCallback(m_context, [](GLFWwindow* window, double xOffset, double yOffset) {
        auto& data = *reinterpret_cast<WindowProps*>(glfwGetWindowUserPointer(window));
        MouseScrolledEvent event(xOffset, yOffset);
        data.callback(event);
    });

    // TODO callbacks:  key pressed, key
    // released
}

Window::~Window()
{
    glfwDestroyWindow(m_context);
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(m_context);
    glfwPollEvents();
}

void Window::setCallbackFunction(const CallbackFn& fn) { m_data.callback = fn; }

} // namespace Engine
