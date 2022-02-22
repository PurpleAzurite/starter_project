#pragma once

// clang-format off
#include "Event.h"
#include "../Logging.h"
// clang-format on

namespace Engine {

class WindowClosedEvent : public Event
{
public:
    EVENT_CLASS_TYPE(windowClosed);
    EVENT_CLASS_CATEGORY(EventCategoryWindow);

    void log() override { ENGINE_INFO("[GLFW] Window closed"); }
};

class WindowMovedEvent : public Event
{
public:
    WindowMovedEvent(int x, int y)
        : m_x(x)
        , m_y(y)
    {
    }

public:
    EVENT_CLASS_TYPE(windowMoved);
    EVENT_CLASS_CATEGORY(EventCategoryWindow);

    void log() override { ENGINE_INFO("[GLFW] Window moved x:{}, y:{}", m_x, m_y); };

private:
    int m_x;
    int m_y;
};

class WindowResizedEvent : public Event
{
public:
    WindowResizedEvent(int width, int height)
        : m_width(width)
        , m_height(height)
    {
    }

public:
    EVENT_CLASS_TYPE(windowResized);
    EVENT_CLASS_CATEGORY(EventCategoryWindow);

    void log() override { ENGINE_INFO("[GLFW] Window resized: {}x{}", m_width, m_height); }

private:
    int m_width;
    int m_height;
};

} // namespace Engine
