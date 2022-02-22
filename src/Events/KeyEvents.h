#pragma once

#include "Event.h"
#include "../Logging.h"

namespace Engine {

class KeyPressedEvent : public Event
{
public:
    KeyPressedEvent(int keyCode) : m_keyCode(keyCode) {}

public:
    EVENT_CLASS_TYPE(keyPressed);
    EVENT_CLASS_CATEGORY(EventCategoryKey | EventCategoryInput);

    void log() override
    {
        ENGINE_INFO("[INPUT] Key pressed: {}", m_keyCode);
    }

private:
    int m_keyCode;
};

class KeyReleasedEvent : public Event
{
public:
    KeyReleasedEvent(int keyCode) : m_keyCode(keyCode) {}

public:
    EVENT_CLASS_TYPE(keyPressed);
    EVENT_CLASS_CATEGORY(EventCategoryKey | EventCategoryInput);

    void log() override
    {
        ENGINE_INFO("[INPUT] Key released: {}", m_keyCode);
    }

private:
    int m_keyCode;
};

}
