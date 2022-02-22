// clang-format off
#include "Window.h"
#include "Events/WindowEvents.h"
#include "GLFW/glfw3.h"
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

    // TODO callbacks: window focus, mouse moved, mouse clicked, mouse scrolled, key pressed, key released
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
