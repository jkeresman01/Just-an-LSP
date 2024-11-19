#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

#include "../enums/TextDocumentSyncKind.h"

namespace justanlsp
{

typedef std::unordered_map<std::string, std::string> CompletionProviderT;

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilities
///
/// @brief ServerCapabilities ...
///
//////////////////////////////////////////////////////////////
class ServerCapabilities
{
    // TODO rest of the capilites (only text is provided for now)

  public:
    ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind, bool areSnippetsSupported,
                       bool isHoverSupported, bool areComletionsSupported);

    class Builder
    {
      public:
        Builder &withTextDocumentSyncKind(const TextDocumentSyncKind &textDocuemntSyncKind)
        {
            m_textDocumentSyncKind = textDocuemntSyncKind;
            return *this;
        }

        Builder &withSnippetSupport(bool areSnippetsSupported)
        {
            m_areSnippetsSupported = areSnippetsSupported;
            return *this;
        }

        Builder &withHoverSupport(bool isHoverSupported)
        {
            m_isHoverSupported = isHoverSupported;
            return *this;
        }

        Builder &withCompletionSupport(bool areCompletionsSupported)
        {
            m_areCompletionsSupported = areCompletionsSupported;
            return *this;
        }

        ServerCapabilities build() const
        {
            return ServerCapabilities(m_textDocumentSyncKind, m_areSnippetsSupported, m_isHoverSupported,
                                      m_areCompletionsSupported);
        }

      private:
        TextDocumentSyncKind m_textDocumentSyncKind;
        bool m_areSnippetsSupported;
        bool m_areCompletionsSupported;
        bool m_isHoverSupported;
    };

    nlohmann::json toJson() const;

  private:
    TextDocumentSyncKind m_textDocumentSyncKind;
    bool m_areSnippetsSupported;
    bool m_areCompletionsSupported;
    bool m_isHoverSupported;

    // TODO
    /* CompletionProviderT m_completionProvider; */
};
} // namespace justanlsp
