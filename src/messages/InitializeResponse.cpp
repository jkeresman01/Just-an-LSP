#include "InitializeResponse.h"

#include <cstdint>
#include <sstream>
#include <string>

namespace justanlsp
{

InitializeResponse::InitializeResponse(const std::string &jsonRPC, const int64_t &id,
                                       const InitializeResult &initializeResult)
    : ResponseMessage(jsonRPC, id), m_initializeResut(initializeResult)
{
}

nlohmann::json InitializeResponse::toJson() const
{
    nlohmann::json InitializeResponsejson = {
        {"jsonrpc", "2.0"},
        {"id", 1},
        {"result",
         {{"serverInfo", m_initializeResut.getServerInfo().toJson()},
          {"capabilities", m_initializeResut.getServerCapabilities().toJson()}}}};

    return InitializeResponsejson;
}

std::string InitializeResponse::toString() const
{
    std::stringstream ss;
    ss << "Initialization response from server { " << m_initializeResut.toString() << " }";
    return ss.str();
}

} // namespace justanlsp
