#include "Window.h"
#include "GLFW/glfw3.h"
#include <utility>

namespace Engine {

Window::Window(WindowProps data) : m_data(std::move(data))
{
    if (!glfwInit())
        ;

    m_context =
        glfwCreateWindow(m_data.width, m_data.height, m_data.title.data(), nullptr, nullptr);

    if (!m_context)
        ;

    glfwMakeContextCurrent(m_context);
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
