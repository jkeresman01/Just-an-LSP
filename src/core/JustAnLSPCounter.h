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
    JustAnLSPCounter(const JustAnLSPCounter &) = delete;
    JustAnLSPCounter(JustAnLSPCounter &&) = delete;
    JustAnLSPCounter &operator=(const JustAnLSPCounter &) = delete;
    JustAnLSPCounter &operator=(JustAnLSPCounter &&) = delete;
    JustAnLSPCounter() { m_justAnLSPCounters.reserve(size_t(RequestType::COUNT)); };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief increments the request counter
    ///
    /// @param requestType
    ///
    //////////////////////////////////////////////////////////////
    void increment(RequestType requestType) { m_justAnLSPCounters[int(requestType)]++; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief increments the requested counter
    ///
    /// @param requestType
    ///
    //////////////////////////////////////////////////////////////
    uint32_t getValue(RequestType requestType) const { return m_justAnLSPCounters[int(requestType)]; };

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
