#pragma once

#include <nlohmann/json.hpp>

#include "../capabilities/TextDocumentSyncClientCapabilites.h"
#include "HoverClientCapabilities.h"

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

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text docuemnt sync capabilities
    ///
    /// @param synchronization capabilites
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncClientCapabilities getTextDocumentSyncCapabilites() const { return m_synchronization; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text docuemnt hover capabilities
    ///
    /// @param hover capabilites
    ///
    //////////////////////////////////////////////////////////////
    HoverClientCapabilities getHoverCapabilities() const { return m_hover; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Capabilities specific to the textDocument syncrhonization
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
