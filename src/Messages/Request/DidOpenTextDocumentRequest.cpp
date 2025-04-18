#include "DidOpenTextDocumentRequest.h"

#include "../Utils/Logger.h"

namespace justanlsp
{
DidOpenTextDocumentRequest::DidOpenTextDocumentRequest(const nlohmann::json &jsonRPC)
    : NotificationMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DidOpenTextDocumentRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("No textDocumentDidChange params in textDocument/DidChange request");
        return;
    }

    m_params = std::make_shared<DidOpenTextDocumentParams>(jsonRPC["params"]);
}

} // namespace justanlsp
