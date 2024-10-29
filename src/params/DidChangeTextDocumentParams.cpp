#include "../params/DidOpenTextDocumentParams.h"

#include "../utils/Logger.h"

namespace justanlsp
{

DidChangeTextDocumenParams::DidChangeTextDocumenParams(const std::nlohamnn::json &jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC);
    setContentChanges(jsonRPC);
}

void DidChangeTextDocumenParams::setTextDocumentIdentifier(const std::nlohamnn::json &jsonRPC)
{
    auto it = jsonRPC.find("textDocument");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No textDocument in textDocument/didChange notification!");
    }
    else
    {
        m_textDocumentItem.URI = jsonRPC["textDocument"];
    }
}

void DidChangeTextDocumenParams::setContentChanges(const std::nlohamnn::json &jsonRPC)
{
    auto it = jsonRPC.find("contentChanges");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No content changes  in textDocument/didChange notification!");
    }
    else
    {
        m_textDocumentItem.URI = jsonRPC["contentChanges"][0];
    }
}
} // namespace justanlsp
