#pragma once

#include <string>

#include "TraceValue.h"

namespace justanlsp
{
class TraceUtil
{
  public:
    TraceUtil() = delete;

    static TraceValue getTraceValue(const std::string &traceValueStr)
    {
        if (traceValueStr == "messages")
        {
            return TraceValue::MESSAGES;
        }

        if (traceValueStr == "verbose")
        {
            return TraceValue::VERBOSE;
        }

        return TraceValue::OFF;
    }
};
} // namespace justanlsp
