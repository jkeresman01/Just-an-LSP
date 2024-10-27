#include "InitializeParams.h"

#include <string>

#include "../utils/Convert.h"
#include "../utils/Logger.h"
#include "../utils/TraceUtil.h"

namespace justanlsp
{

InitializeParams::InitializeParams(const nlohmann::json &jsonRPC)
{
    setProccessId(jsonRPC);
    setLocale(jsonRPC);
    setClientInfo(jsonRPC);
    setTraceLevel(jsonRPC);
}

void InitializeParams::setProccessId(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("proccessId");
    if (it == jsonRPC.end())
    {
        LOG_ERROR << "No locale value was set in Initialize request";
    }
    else
    {
        std::string processIdStr = std::string(jsonRPC["proccessId"]);
        m_processId = Converter::convert<int64_t>(processIdStr);
    }
}

void InitializeParams::setLocale(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("locale");
    if (it == jsonRPC.end())
    {
        LOG_ERROR << "No locale value was set in Initialize request";
    }
    else
    {
        std::string locale = std::string(jsonRPC["locale"]);
        m_locale = locale;
    }
}

void InitializeParams::setClientInfo(const nlohmann::json &jsonRPC)
{
    nlohmann::json clientInfoJson = jsonRPC["clientInfo"];

    m_clientInfo.name = std::string(clientInfoJson["name"]);
    m_clientInfo.version = std::string(clientInfoJson["version"]);
}

void InitializeParams::setTraceLevel(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("trace");
    if (it == jsonRPC.end())
    {
        LOG_INFO << "No trace value set in Initialize request, defaultin to TraceValue::OFF";
        m_traceValue = TraceValue::OFF;
    }
    else
    {
        std::string traceStr = std::string(jsonRPC["trace"]);
        m_traceValue = TraceUtil::getTraceValue(traceStr);
    }
}

} // namespace justanlsp
