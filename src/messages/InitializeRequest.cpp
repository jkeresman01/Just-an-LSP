#include "InitializeRequest.h"

namespace justanlsp
{

InitializeRequest::InitializeRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    m_initializeParams = std::make_shared<InitializeParams>(jsonRPC);
}

} // namespace justanlsp
