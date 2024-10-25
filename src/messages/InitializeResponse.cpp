#include "InitializeResponse.h"

#include <sstream>
#include <string>

namespace justanlsp
{

InitializeResponse::InitializeResponse(const ServerInfo &serverInfo,
                                       const ServerCapabilities &serverCapabilites)
    : Message("2.0"), m_serverInfo(serverInfo), m_serverCapabilities(serverCapabilites)
{
}

nlohmann::json InitializeResponse::toJson() const
{
    nlohmann::json initializeResponseJson = {{"jsonrpc", m_jsonRPC},
                                             {"serverInfo",
                                              {
                                                  {"name", m_serverInfo.name},
                                                  {"version", m_serverInfo.version},
                                              }},
                                             {"capabilities", m_serverCapabilities.toJson()}};

    return initializeResponseJson;
}

std::string InitializeResponse::toString() const
{
    std::stringstream ss;
    ss << "Initialization response from server { " << m_serverInfo.toString() << " }";
    return ss.str();
}

} // namespace justanlsp
