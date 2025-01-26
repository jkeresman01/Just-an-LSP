#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

#include "../Enums/TextDocumentSyncKind.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilities
///
/// @brief Encapsulates server capabilities, including support for
///        text synchronization, hover, snippet completions, and
///        other features of the language server.
///
//////////////////////////////////////////////////////////////
class ServerCapabilities
{
    // TODO: Extend the implementation for additional capabilities.

  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs server capabilities
    ///
    /// @param textDocumentSyncKind
    /// @param areSnippetsSupported
    /// @param isHoverSupported
    /// @param areCompletionsSupported
    ///
    //////////////////////////////////////////////////////////////
    ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind, bool areSnippetsSupported,
                       bool isHoverSupported, bool areCompletionsSupported, bool areCodeActionsSupported);

    //////////////////////////////////////////////////////////////
    ///
    /// @class Builder
    ///
    /// @brief Constructs instances of ServerCapabilities using a
    ///        fluent interface for customization.
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
      public:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the text document synchronization kind.
        ///
        /// @param textDocuemntSyncKind TextDocumentSyncKind enum value.
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withTextDocumentSyncKind(const TextDocumentSyncKind &textDocuemntSyncKind)
        {
            m_textDocumentSyncKind = textDocuemntSyncKind;
            return *this;
        }

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables snippet support.
        ///
        /// @param areSnippetsSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withSnippetSupport(bool areSnippetsSupported)
        {
            m_areSnippetsSupported = areSnippetsSupported;
            return *this;
        }

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables hover functionality.
        ///
        /// @param isHoverSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withHoverSupport(bool isHoverSupported)
        {
            m_isHoverSupported = isHoverSupported;
            return *this;
        }

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables completion support.
        ///
        /// @param areCompletionsSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCompletionSupport(bool areCompletionsSupported)
        {
            m_areCompletionsSupported = areCompletionsSupported;
            return *this;
        }

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables code action support.
        ///
        /// @param areCodeActions
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCodeActionSupport(bool areCodeActionsSupported)
        {
            m_areCodeActionsSupported = areCodeActionsSupported;
            return *this;
        }

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Constructs a ServerCapabilities instance based on
        ///        the set parameters.
        ///
        /// @return A ServerCapabilities instance.
        ///
        //////////////////////////////////////////////////////////////
        ServerCapabilities build() const
        {
            return ServerCapabilities(m_textDocumentSyncKind, m_areSnippetsSupported, m_isHoverSupported,
                                      m_areCompletionsSupported, m_areCodeActionsSupported);
        }

      private:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Synchronization kind for text documents.
        ///
        //////////////////////////////////////////////////////////////
        TextDocumentSyncKind m_textDocumentSyncKind;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether snippets are supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areSnippetsSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether completions are supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areCompletionsSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether hover functionality is supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_isHoverSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether code action functionality is supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areCodeActionsSupported;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the ServerCapabilities instance to its
    ///        JSON representation.
    ///
    /// @return server capabilities in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Synchronization kind for text documents.
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncKind m_textDocumentSyncKind;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether snippets are supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areSnippetsSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether completions are supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areCompletionsSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether hover functionality is supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_isHoverSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether hover functionality is supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areCodeActionsSupported;
};
} // namespace justanlsp
