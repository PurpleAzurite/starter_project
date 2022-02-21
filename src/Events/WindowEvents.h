#pragma once

#include "Event.h"

namespace Engine {

class WindowClosedEvent : public Event
{
public:
    EVENT_CLASS_TYPE(windowClosed);
    void log() {}
};

} // namespace Engine
