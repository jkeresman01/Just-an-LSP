#include "InitializeParams.h"

#include <string>

#include "../utils/TraceUtil.h"

namespace justanlsp
{

InitializeParams::InitializeParams(const nlohmann::json &jsonRPC)
    : m_processId(jsonRPC["proccessId"]), m_locale(jsonRPC["locale"])
{
    nlohmann::json clientInfoJson = jsonRPC["clientInfo"];
    m_clientInfo.name = clientInfoJson["name"];
    m_clientInfo.version = clientInfoJson["version"];

    auto it = jsonRPC.find("trace");
    if (it == jsonRPC.end())
    {
        m_traceValue = TraceValue::OFF;
    }
    else
    {
        std::string traceStr = std::string(jsonRPC["trace"]);
        m_traceValue = TraceUtil::getTraceValue(traceStr);
    }
}

} // namespace justanlsp
