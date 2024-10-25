#include "RequestMessage.h"

#include "../utils/MessageUtil.h"
#include <nlohmann/json.hpp>

namespace justanlsp
{

RequestMessage::RequestMessage(const std::string &jsonRPC) : Message("2.0")
{
    nlohmann::json json = MessageUtil::tryParse(jsonRPC);
    m_method = json["method"];
    m_id = json["id"];
}

} // namespace justanlsp
