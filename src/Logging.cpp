#include "Logging.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {

std::shared_ptr<spdlog::logger> Logger::s_engineLogger;

void Logger::init()
{
    #ifdef DEBUG_BUILD
    if (!s_engineLogger)
    {
        s_engineLogger = spdlog::stdout_color_mt("Engine");
        s_engineLogger->info("Logger initialized");
    }
    #endif
}

}
