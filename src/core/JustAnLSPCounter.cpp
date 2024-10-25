#include "JustAnLSPCounter.h"
#include "../utils/Logger.h"

#include <numeric>

namespace justanlsp
{
JustAnLSPCounter::JustAnLSPCounter()
{
    m_justAnLSPCounters.reserve(size_t(RequestType::COUNT));
}

void JustAnLSPCounter::increment(RequestType requestType)
{
    LOG_INFO << "Incrementing counter ";
    m_justAnLSPCounters[requestType]++;
    LOG_INFO << "Finished incrementing";
};

uint32_t JustAnLSPCounter::getValue(RequestType requestType) const
{
    return m_justAnLSPCounters[int(requestType)];
};

uint32_t JustAnLSPCounter::getSum() const
{
    return std::accumulate(m_justAnLSPCounters.begin(), m_justAnLSPCounters.end(), 0);
}
} // namespace justanlsp
