#include "DidChangeTextDocumentRequest.h"

#include "../utils/Logger.h"

namespace justanlsp
{
DidChangeTextDocumentRequest::DidChangeTextDocumentRequest(const nlohmann::json &jsonRPC)
    : NotificationMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DidChangeTextDocumentRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No params in textDocument/didChange notification!");
        return;
    }

    m_didChangeTextDocumentParams = std::make_shared<DidChangeTextDocumentParams>(jsonRPC["params"]);
}
} // namespace justanlsp
