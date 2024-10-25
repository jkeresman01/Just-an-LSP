#pragma once

#include <cstdint>
#include <vector>

#include "../enums/RequestType.h"

namespace justanlsp
{
class JustAnLSPCounter
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPCounter();

    JustAnLSPCounter(const JustAnLSPCounter &) = delete;
    JustAnLSPCounter(JustAnLSPCounter &&) = delete;
    JustAnLSPCounter &operator=(const JustAnLSPCounter &) = delete;
    JustAnLSPCounter &operator=(JustAnLSPCounter &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Increments the request counter
    ///
    /// @param requestType
    ///
    //////////////////////////////////////////////////////////////
    void increment(RequestType requestType);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the value of requested counter
    ///
    /// @param requestType
    ///
    //////////////////////////////////////////////////////////////
    uint32_t getValue(RequestType requestType) const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the accumulated sum of all counters
    ///
    //////////////////////////////////////////////////////////////
    uint32_t getSum() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Keeps track of received requests
    ///
    /// @param requestType
    ///
    //////////////////////////////////////////////////////////////
    std::vector<uint32_t> m_justAnLSPCounters;
};
} // namespace justanlsp
