#include "RequestMessage.h"

#include "../utils/Convert.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"
#include "Message.h"
#include <nlohmann/json.hpp>

namespace justanlsp
{

RequestMessage::RequestMessage(const nlohmann::json &jsonRPC) : Message(jsonRPC["jsonrpc"])
{
    setId(jsonRPC);
    setMethod(jsonRPC);
}

void RequestMessage::setId(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("id");

    if (it == jsonRPC.end())
    {
        LOG_ERROR << "Can't construct Request message, there is no method in request";
    }
    else
    {
        std::string idStr = std::string(jsonRPC["id"]);
        m_id = Converter::convert<int64_t>(idStr);
    }
}

void RequestMessage::setMethod(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("method");

    if (it == jsonRPC.end())
    {
        LOG_ERROR << "Can't construct Request message, there is no method in request";
    }
    else
    {
        m_method = std::string(jsonRPC["method"]);
    }
}

} // namespace justanlsp
