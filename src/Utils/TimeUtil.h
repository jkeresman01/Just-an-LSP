#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <ostream>

namespace justanlsp
{

/////////////////////////////////////////////////////////////////////
///
/// @class TimeUtil
///
/// @brief Utility class for time related stuff
///
/////////////////////////////////////////////////////////////////////
class TimeUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    TimeUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the current time
    ///
    /////////////////////////////////////////////////////////////////////
    static std::time_t now();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Print and format provided time
    ///
    /// @param out
    /// @param time
    ///
    /////////////////////////////////////////////////////////////////////
    static std::ostream &putTime(std::ostream &out, const std::time_t &time);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline std::time_t TimeUtil::now()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime =
        std::chrono::high_resolution_clock::now();
    return std::chrono::high_resolution_clock::to_time_t(currentTime);
}

inline std::ostream &TimeUtil::putTime(std::ostream &out, const std::time_t &time)
{
    return out << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
}

} // namespace justanlsp
