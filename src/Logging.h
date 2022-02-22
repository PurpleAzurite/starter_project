#pragma once

// clang-format off
#include <spdlog/logger.h>
#include <memory>
// clang-format off

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

}
