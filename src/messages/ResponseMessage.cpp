#include "ResponseMessage.h"

namespace justanlsp
{

nlohmann::json ResponseMessage::toJson() const
{
    nlohmann::json responseMsgJson = {
        Message::toJson(),
        {"id", m_id},
    };

    return responseMsgJson;
}
} // namespace justanlsp
