#include "InitializeParams.h" #include < string> #include "../utils/Convert.h" #include "../utils/Logger.h" #include "../utils/TraceUtil.h"
namespace justanlsp
{

InitializeParams::InitializeParams(const nlohmann::json &jsonInitializeParams)
{
    setProccessId(jsonInitializeParams);
    setClientInfo(jsonInitializeParams);
}

void InitializeParams::setProccessId(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("processId");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No process id was set in request");
    }
    else
    {
        m_processId = jsonRPC["processId"];
    }
}

void InitializeParams::setLocale(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("locale");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No locale value was set in Initialize request");
    }
    else
    {
        m_locale = jsonRPC["locale"];
    }
}

void InitializeParams::setClientInfo(const nlohmann::json &jsonRPC)
{
    nlohmann::json clientInfoJson = jsonRPC["clientInfo"];

    m_clientInfo.name = clientInfoJson["name"];
    m_clientInfo.version = clientInfoJson["version"];
}

void InitializeParams::setTraceLevel(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("trace");

    if (it == jsonRPC.end())
    {
        LOG_INFO("No trace value set in Initialize request, defaultin to TraceValue::OFF");
        m_traceValue = TraceValue::OFF;
    }
    else
    {
        m_traceValue = jsonRPC["trace"];
    }
}

} // namespace justanlsp
