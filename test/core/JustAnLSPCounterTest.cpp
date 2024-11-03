#include <gtest/gtest.h>

#include "../../src/core/JustAnLSPCounter.h"
#include "../../src/enums/RequestType.h"

namespace justanlsp
{
class JustAnLSPCounterTest : public ::testing::Test
{
  protected:
    JustAnLSPCounter justAnLSPCounters;
};

TEST_F(JustAnLSPCounterTest, WillIncrementRequestTypeCorrectly)
{
    // WHEN
    justAnLSPCounters.increment(RequestType::INITIALIZE);

    // THEN
    EXPECT_EQ(justAnLSPCounters.getValue(RequestType::INITIALIZE), 1);
}

TEST_F(JustAnLSPCounterTest, WillReturnCorrectValueForEachRequestType)
{
    // WHEN
    justAnLSPCounters.increment(RequestType::INITIALIZE);
    justAnLSPCounters.increment(RequestType::INITIALIZE);
    justAnLSPCounters.increment(RequestType::SHUTDOWN);

    // THEN
    EXPECT_EQ(justAnLSPCounters.getValue(RequestType::INITIALIZE), 2);
    EXPECT_EQ(justAnLSPCounters.getValue(RequestType::SHUTDOWN), 1);
}

TEST_F(JustAnLSPCounterTest, WillReturnCorrectSumAfterMultipleIncrements)
{
    // WHEN
    justAnLSPCounters.increment(RequestType::INITIALIZE);
    justAnLSPCounters.increment(RequestType::INITIALIZED);
    justAnLSPCounters.increment(RequestType::TEXT_DOCUMENT_DID_OPEN);
    justAnLSPCounters.increment(RequestType::TEXT_DOCUMENT_HOVER);

    // THEN
    uint32_t totalSum = justAnLSPCounters.getSum();

    EXPECT_EQ(totalSum, 4);
}

TEST_F(JustAnLSPCounterTest, WillReturnZeroSumForNewCounter)
{
    // WHEN
    uint32_t totalSum = justAnLSPCounters.getSum();

    // THEN
    EXPECT_EQ(totalSum, 0);
}

TEST_F(JustAnLSPCounterTest, WillReturnZeroForUnincrementedRequestType)
{
    // WHEN
    uint32_t value = justAnLSPCounters.getValue(RequestType::TEXT_DOCUMENT_COMPLETION);

    // THEN
    EXPECT_EQ(value, 0);
}

} // namespace justanlsp
