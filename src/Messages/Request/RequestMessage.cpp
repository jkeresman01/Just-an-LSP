#include "RequestMessage.h"

#include "../Utils/Convert.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"
#include "Message.h"
#include <nlohmann/json.hpp>

namespace justanlsp
{

RequestMessage::RequestMessage(const nlohmann::json &jsonRPC) : Message("2.0")
{
    setId(jsonRPC);
    setMethod(jsonRPC);
}

void RequestMessage::setId(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("id");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("Can't construct Request message, there is no id in request");
        return;
    }

    m_id = jsonRPC["id"];
}

void RequestMessage::setMethod(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("method");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("Can't construct Request message, there is no method in request");
        return;
    }

    m_method = jsonRPC["method"];
}

} // namespace justanlsp
