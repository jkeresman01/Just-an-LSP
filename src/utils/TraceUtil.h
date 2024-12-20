#pragma once

#include <string>

#include "../enums/TraceValue.h"

namespace justanlsp
{

/////////////////////////////////////////////////////////////////////
///
/// @class TraceUtil
///
/// @brief Utility class for trace related stuff
///
/////////////////////////////////////////////////////////////////////
class TraceUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    TraceUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts string trace value to enum representation
    ///
    /// @param traceValueStr
    ///
    /////////////////////////////////////////////////////////////////////
    static TraceValue getTraceValue(const std::string &traceValueStr);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

TraceValue inline getTraceValue(const std::string &traceValueStr)
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

} // namespace justanlsp
