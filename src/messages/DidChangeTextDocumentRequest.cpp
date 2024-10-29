#include "DidChangeTextDocumentRequest.h"

#include <memory>

#include "../utils/Logger.h"

namespace justanlsp
{
DidChangeTextDocumentRequest::DidChangeTextDocumentRequest(const std::nlohamnn::json &jsonRPC)
    : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DidChangeTextDocumentRequest::setParams(const std::nlohamnn::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No params in textDocument/didChange notification!");
    }
    else
    {
        m_didChangeTextDocumentParams = std::make_shared<DidChangeTextDocumenParams>(jsonRPC["params"]);
    }
}
} // namespace justanlsp
