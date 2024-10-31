#include "../messages/NotificationMessage.h"

namespace justanlsp
{

NotificationMessage::NotificationMessage(const nlohmann::json &jsonRPC)
    : Message("2.0"), m_method(jsonRPC["method"])
{
}

} // namespace justanlsp
