#include "ServerCapabilities.h"

namespace justanlsp
{

ServerCapabilities::ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind)
    : m_textDocumentSyncKind(textDocumentSyncKind)
{
}

nlohmann::json ServerCapabilities::toJson() const
{
    nlohmann::json serverCapabilitiesJson = {{"textDocumentSync", m_textDocumentSyncKind}};
    return serverCapabilitiesJson;
}
} // namespace justanlsp
