#include "RequestMessage.h"
#include "Message.h"

namespace justanlsp
{

RequestMessage::RequestMessage(const std::string &jsonRPC, const std::string &method, int32_t id)
    : Message(jsonRPC), m_method(method), m_id(id)
{
}

} // namespace justanlsp
