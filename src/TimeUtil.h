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
    static std::time_t now()
    {
        auto current_time = std::chrono::high_resolution_clock::now();
        return std::chrono::high_resolution_clock::to_time_t(current_time);
    }

    static std::ostream &putTime(std::ostream &out, const std::time_t &time)
    {
        return out << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    }
};
} // namespace justanlsp
