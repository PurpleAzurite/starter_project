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
    void log() { ENGINE_INFO("Window closed"); }
};

} // namespace Engine
