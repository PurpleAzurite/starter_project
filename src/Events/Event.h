#pragma once

#define BIT(x) (1 << x)

namespace Engine {

enum class EventType {
    none = 0,
    windowClosed,
    windowMoved,
    windowResized,
    windowFocused,
    windowLostFocus,
    mouseMoved,
    mouseButtonPressed,
    mouseButtonReleased,
    mouseScrolled,
    keyPressed,
    keyReleased,
};

enum EventCategory {
    none = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryWindow = BIT(1),
    EventCategoryInput = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryKey = BIT(4),
};

#define EVENT_CLASS_TYPE(x)                                                                        \
    static EventType staticType() { return EventType::x; }                                         \
    EventType eventType() const override { return staticType(); }

#define EVENT_CLASS_CATEGORY(x)                                                                    \
    virtual int categoryFlags() const override { return EventCategory::x; }

struct Event
{
    Event() = default;
    virtual ~Event() = default;

    virtual EventType eventType() const = 0;
    virtual int categoryFlags() const = 0;

    bool isInCategory(EventCategory category) const { return categoryFlags() & category; }

    virtual void log() = 0;

    bool handled = false;
};

class EventDispatcher
{
public:
    EventDispatcher(Event& event)
        : m_event(event)
    {
    }

public:
    template <typename T, typename F>
    bool dispatch(const F& fn)
    {
        if (m_event.eventType() == T::staticType())
        {
            m_event.handled |= fn(static_cast<T&>(m_event));
            return true;
        }

        return false;
    }

private:
    Event& m_event;
};

} // namespace Engine
