#include "NotificationMessage.h"

namespace lsp
{

NotificationMessage::NotificationMessage(const std::string& method,
                                         const std::string& jsonRPC) 
    : Message(jsonRPC),
    m_method(method)
{
}
    
} // lsp

