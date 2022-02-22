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

    void log() override { ENGINE_INFO("Window closed"); }
};

} // namespace Engine
