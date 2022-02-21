#pragma once

namespace Engine {

enum class EventType {
    none = 0,
    windowClosed,
    windowMoved,
    windowResized,
    windowFocused,
    windowLostFocus,
};

#define EVENT_CLASS_TYPE(x)                                                                        \
    static EventType staticType() { return EventType::x; }                                         \
    virtual EventType eventType() const { return staticType(); }

struct Event
{
    Event() = default;
    virtual ~Event() = default;

    virtual EventType eventType() const = 0;
    virtual void log() = 0;

    bool handled = false;
};

class EventDispatcher
{
public:
    EventDispatcher(Event& event) : m_event(event) {}

public:
    template <typename T, typename F>
    bool dispatch(const F& fn)
    {
        if (m_event.eventType() == T::staticType()) {
            m_event.handled |= fn(static_cast<T&>(m_event));
            return true;
        }

        return false;
    }

private:
    Event& m_event;
};

} // namespace Engine
