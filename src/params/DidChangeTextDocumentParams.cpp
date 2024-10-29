#include "DidChangeTextDocumentParams.h"

#include "../utils/Logger.h"

namespace justanlsp
{

DidChangeTextDocumenParams::DidChangeTextDocumenParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC);
    setContentChanges(jsonRPC);
}

void DidChangeTextDocumenParams::setTextDocumentIdentifier(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("textDocument");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No textDocument in textDocument/didChange notification!");
    }
    else
    {
        m_textDocument.URI = jsonRPC["textDocument"];
    }
}

void DidChangeTextDocumenParams::setContentChanges(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("contentChanges");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No content changes  in textDocument/didChange notification!");
    }
    else
    {
        m_contentChanges = jsonRPC["contentChanges"][0];
    }
}
} // namespace justanlsp
