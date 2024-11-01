#include "DidChangeTextDocumentParams.h"

#include "../utils/Logger.h"

namespace justanlsp
{

DidChangeTextDocumentParams::DidChangeTextDocumentParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC["textDocument"]);
    setContentChanges(jsonRPC["contentChanges"][0]);
}

void DidChangeTextDocumentParams::setTextDocumentIdentifier(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No textDocument in textDocument/didChange notification!");
    }
    else
    {
        m_textDocument.URI = jsonRPC["uri"];
    }
}

void DidChangeTextDocumentParams::setContentChanges(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("text");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No text changes in textDocument/didChange notification!");
    }
    else
    {
        m_contentChanges = jsonRPC["text"];
    }
}
} // namespace justanlsp
