#pragma once

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @enum RequestType
///
/// @brief Describes possible request types that client can make
///
///
//////////////////////////////////////////////////////////////
enum class RequestType
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Initialize request as defined by LSP protocol
    ///
    //////////////////////////////////////////////////////////////
    INITIALIZE,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/DidChange request as defined by LSP protocol
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_DID_OPEN,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/DidChange request as defined by LSP protocol
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_DID_CHANGE,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/Hover request as defined by LSP protocol
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_HOVER,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unkown request type
    ///
    //////////////////////////////////////////////////////////////
    UNKNOWN,
};

} // namespace justanlsp
