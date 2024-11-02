#include "TextDocumentPositionParams.h"

#include "../utils/Logger.h"

namespace justanlsp
{
TextDocumentPositionParams::TextDocumentPositionParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC["textDocument"]);
    setPostion(jsonRPC["position"]);
}

void TextDocumentPositionParams::setPostion(const nlohmann::json &jsonRPC)
{
    m_position.line = jsonRPC["line"];
    m_position.character = jsonRPC["character"];
}

void TextDocumentPositionParams::setTextDocumentIdentifier(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LOG_ERROR("No text docuemnt identifier in TextDocumentPositionParams");
    }
    else
    {
        m_textDocument.URI = jsonRPC["uri"];
    }
}
} // namespace justanlsp
