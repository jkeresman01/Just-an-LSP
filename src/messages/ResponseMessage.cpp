#include "ResponseMessage.h"

namespace justanlsp
{

nlohmann::json ResponseMessage::toJson() const
{
    return {
        Message::toJson(),
        {"id", m_id},
    };
}
} // namespace justanlsp
