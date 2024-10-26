#include "InitializeResult.h"

#include <sstream>
#include <string>

namespace justanlsp
{

InitializeResult::InitializeResult(const ServerInfo &serverInfo, const ServerCapabilities &serverCapabilites)
    : m_serverInfo(serverInfo), m_serverCapabilities(serverCapabilites)
{
}

nlohmann::json InitializeResult::toJson() const
{
    nlohmann::json initializeresponsejson = {{"serverinfo", {m_serverInfo.toJson()}},
                                             {"capabilites", {m_serverCapabilities.toJson()}}};

    return initializeresponsejson;
}

std::string InitializeResult::toString() const
{
    std::stringstream ss;
    ss << "Initialization result for server { " << m_serverInfo.toString() << " }";
    return ss.str();
}

} // namespace justanlsp
