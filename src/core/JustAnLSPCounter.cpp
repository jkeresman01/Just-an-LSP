#include "JustAnLSPCounter.h"
#include "../utils/Logger.h"

#include <cstdint>
#include <numeric>

namespace justanlsp
{
JustAnLSPCounter::JustAnLSPCounter()
{
    m_justAnLSPCounters.reserve(static_cast<size_t>(RequestType::COUNT));
}

void JustAnLSPCounter::increment(RequestType requestType)
{
    m_justAnLSPCounters[static_cast<int32_t>(requestType)]++;
};

uint32_t JustAnLSPCounter::getValue(RequestType requestType) const
{
    return m_justAnLSPCounters[static_cast<int32_t>(requestType)];
};

uint32_t JustAnLSPCounter::getSum() const
{
    return std::accumulate(m_justAnLSPCounters.begin(), m_justAnLSPCounters.end(), 0);
}
} // namespace justanlsp
