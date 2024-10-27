#pragma once

#include <memory>

#include "../params/DidOpenTextDocumentParams.h"
#include "NotificationMessage.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class DidOpenTextDocumentRequest
///
/// @brief Represents a request message for the textDocument/didOpen request
///        in the Language Server Protocol (LSP).
///
//////////////////////////////////////////////////////////////
class DidOpenTextDocumentRequest : public NotificationMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a DidOpenTextDocumentRequest from a JSON-RPC request.
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    DidOpenTextDocumentRequest(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sets the parameters for the textDocument/didOpen request.
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the parameters for the textDocument/didOpen request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DidOpenTextDocumentParams> m_params;
};
} // namespace justanlsp
