#include "ServerCapabilities.h"

namespace justanlsp
{

ServerCapabilities::ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind)
    : m_textDocumentSyncKind(textDocumentSyncKind)
{
}

nlohmann::json ServerCapabilities::toJson() const
{
    return {
        {"textDocumentSync", m_textDocumentSyncKind}, {"completionProvider", "{}"}, {"hoverProvider", true}};
}
} // namespace justanlsp
