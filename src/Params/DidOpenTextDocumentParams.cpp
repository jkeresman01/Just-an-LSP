#include "DidOpenTextDocumentParams.h"

#include "../Utils/Logger.h"

namespace justanlsp
{
DidOpenTextDocumentParams::DidOpenTextDocumentParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentItemKind(jsonRPC);
}

void DidOpenTextDocumentParams::setTextDocumentItemKind(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("textDocument");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("No textDocument in textDocument/didOpen request");
        return;
    }

    m_textDocumentItem = std::make_shared<TextDocumentItem>(jsonRPC["textDocument"]);
}
} // namespace justanlsp
