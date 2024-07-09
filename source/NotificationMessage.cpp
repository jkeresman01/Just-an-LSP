#include "NotificationMessage.h"

namespace justanlsp
{

NotificationMessage::NotificationMessage(const std::string& method,
                                         const std::string& jsonRPC) 
    : Message(jsonRPC),
    m_method(method)
{
}
    
} // justanlsp
