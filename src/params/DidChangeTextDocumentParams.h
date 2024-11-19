#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../types/TextDocumentIdentifier.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class DidChangeTextDocumentParams
///
/// @brief Handles the parameters for the `textDocument/didChange`
///        notification in the Language Server Protocol (LSP).
//
//////////////////////////////////////////////////////////////
class DidChangeTextDocumentParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs DidChangeTextDocumentParams from a JSON-RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit DidChangeTextDocumentParams(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for changed docuemnt URI
    ///
    //////////////////////////////////////////////////////////////
    std::string getChangedDocumentURI() const { return m_textDocument.URI; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for document changes
    ///
    //////////////////////////////////////////////////////////////
    std::string getContentChanges() const { return m_contentChanges; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for text document identifier
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setTextDocumentIdentifier(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for content changes
    ///
    /// @param jsonRPC The JSON-RPC object containing LSP message data.
    ///
    //////////////////////////////////////////////////////////////
    void setContentChanges(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Identifier of the text document that has changed.
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentIdentifier m_textDocument;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Represents content changes in the document.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_contentChanges;
};

} // namespace justanlsp
