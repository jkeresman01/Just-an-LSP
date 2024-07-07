#include "RequestMessage.h"
#include "Message.h"

namespace lsp
{

RequestMessage::RequestMessage(const std::string &jsonRPC,
                               const std::string& method,
                               int32_t id)
    :Message(jsonRPC),
    m_method(method),
    m_id(id)
{
};

nlohmann::json RequestMessage::toJson() const 
{
    // TODO convert to JSON
    return "";
}
        
} // lsp

