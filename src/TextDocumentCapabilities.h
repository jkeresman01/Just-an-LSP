#pragma once

#include <memory>
#include <nlohmann/json.hpp>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class TextDocumentCapabilities
///
/// @brief TextDocumentClientCapabilities define capabilities
///        the editor / tool provides on text documents.
///
//////////////////////////////////////////////////////////////
class TextDocumentCapabilities
{
    // TODO reset of the capabilities only sync and hover are currently included

  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the TextDocumentCapabilities from jsonRPC request
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentCapabilities(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Capabilities specific to the textDocument syncrhonization
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncClientCapabilities m_synchronization;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Capabilities specific to the `textDocument/hover` request.
    ///
    //////////////////////////////////////////////////////////////
    HoverClientCapabilities m_hover;
};
} // namespace justanlsp
