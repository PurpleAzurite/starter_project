#pragma once

// clang-format off
#include "Event.h"
#include "../Logging.h"
// clang-format on

namespace Engine {

class MouseMovedEvent : public Event
{
public:
    MouseMovedEvent(double x, double y)
        : m_x(x)
        , m_y(y)
    {
    }

public:
    EVENT_CLASS_TYPE(mouseMoved);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    void log() override { ENGINE_INFO("[INPUT] Mouse moved: {},{}", m_x, m_y); }

private:
    double m_x;
    double m_y;
};

class MouseButtonPressedEvent : public Event
{
public:
    MouseButtonPressedEvent(int keyCode)
        : Event()
        , m_keyCode(keyCode)
    {
    }

public:
    EVENT_CLASS_TYPE(mouseButtonPressed);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    void log() override { ENGINE_INFO("[INPUT] Mouse button pressed: {}", m_keyCode); }

private:
    int m_keyCode;
};

class MouseButtonReleasedEvent : public Event
{
public:
    MouseButtonReleasedEvent(int keyCode)
        : Event()
        , m_keyCode(keyCode)
    {
    }

public:
    EVENT_CLASS_TYPE(mouseButtonPressed);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    void log() override { ENGINE_INFO("[INPUT] Mouse button released: {}", m_keyCode); }

private:
    int m_keyCode;
};

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(double xOffset, double yOffset)
        : m_xOffset(xOffset)
        , m_yOffset(yOffset)
    {
    }

    EVENT_CLASS_TYPE(mouseScrolled);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    void log() override
    {
        ENGINE_INFO("Mouse scrolled along the {} axis by {}", m_xOffset ? "x" : "y",
                    m_yOffset ? m_yOffset : m_xOffset);
    }

private:
    double m_xOffset;
    double m_yOffset;
};

} // namespace Engine
