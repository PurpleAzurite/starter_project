#pragma once

// clang-format off
#include <spdlog/logger.h>
#include <memory>
// clang-format on

namespace Engine {

class Logger
{
private:
    Logger() = default;

public:
    static void init();

public:
    static inline std::shared_ptr<spdlog::logger>& engine() { return s_engineLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_engineLogger;
};

} // namespace Engine

#ifdef DEBUG_BUILD
#define ENGINE_INFO(...) Engine::Logger::engine()->info(__VA_ARGS__)
#define ENGINE_WARN(...) Engine::Logger::engine()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) Engine::Logger::engine()->error(__VA_ARGS__)
#else
#define ENGINE_INFO(...)
#define ENGINE_WARN(...)
#define ENGINE_ERROR(...)
#endif
