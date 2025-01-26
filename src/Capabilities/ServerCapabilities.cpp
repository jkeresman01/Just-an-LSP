#include "ServerCapabilities.h"

namespace justanlsp
{

ServerCapabilities::ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind,
                                       bool areSnippetsSupported, bool isHoverSupported,
                                       bool areComletionsSupported, bool areCodeActionsSupported, bool areDefintionsSupported)
    : m_textDocumentSyncKind(textDocumentSyncKind), m_areSnippetsSupported(areSnippetsSupported),
      m_areCompletionsSupported(areSnippetsSupported), m_isHoverSupported(isHoverSupported),
      m_areCodeActionsSupported(areCodeActionsSupported), m_areDefinitionsSupported(areSnippetsSupported)
{
}

nlohmann::json ServerCapabilities::toJson() const
{
    return {{"textDocumentSync", m_textDocumentSyncKind},
            {"completionProvider", "{}"},
            {"hoverProvider", true},
            {"codeActionProvider", true},
            {"definitionProvider", true}};
}
} // namespace justanlsp
