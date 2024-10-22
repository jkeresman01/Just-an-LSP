#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <ostream>

namespace justanlsp
{

class TimeUtil
{
  public:
    TimeUtil() = delete;

    static std::time_t now()
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> currentTime =
            std::chrono::high_resolution_clock::now();
        return std::chrono::high_resolution_clock::to_time_t(currentTime);
    }

    static std::ostream &putTime(std::ostream &out, const std::time_t &time)
    {
        return out << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    }
};
} // namespace justanlsp
