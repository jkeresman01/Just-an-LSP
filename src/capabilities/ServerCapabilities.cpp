#include "ServerCapabilities.h"

namespace justanlsp
{

ServerCapabilities::ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind,
                                       bool areSnippetsSupported, bool isHoverSupported,
                                       bool areComletionsSupported)
    : m_textDocumentSyncKind(textDocumentSyncKind), m_areSnippetsSupported(areSnippetsSupported),
      m_areCompletionsSupported(areSnippetsSupported), m_isHoverSupported(isHoverSupported)
{
}

nlohmann::json ServerCapabilities::toJson() const
{
    return {
        {"textDocumentSync", m_textDocumentSyncKind}, {"completionProvider", "{}"}, {"hoverProvider", true}};
}
} // namespace justanlsp
