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
    /// @brief initialize request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    INITIALIZE,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shutdown request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    SHUTDOWN,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief initialized request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    INITIALIZED,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/didOpen request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_DID_OPEN,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/didChange request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_DID_CHANGE,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/hover request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_HOVER,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/completion request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_COMPLETION,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/codeAction request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_CODE_ACTION,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/defintion request as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    TEXT_DOCUMENT_DEFINITION,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unkown request type as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    UNKNOWN,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Exit notification as defined by LSP
    ///
    //////////////////////////////////////////////////////////////
    EXIT,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Max number of request types
    ///
    //////////////////////////////////////////////////////////////
    COUNT,
};

} // namespace justanlsp
