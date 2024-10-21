#pragma once

#include <cstdint>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @enum ErrorCodes
///
/// @brief Enumeration containing all possible error codes
///
//////////////////////////////////////////////////////////////
enum class ErrorCodes : int32_t
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Parse error, error code defined by JSON RPC
    ///
    //////////////////////////////////////////////////////////////
    PARSE_ERROR = -32700,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Invalid request, error code defined by JSON RPC
    ///
    //////////////////////////////////////////////////////////////
    INVALID_REQUEST = -32600,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Method not found, error code defined by JSON RPC
    ///
    //////////////////////////////////////////////////////////////
    METHOD_NOT_FOUND = -31601,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Invalid params, error code defined by JSON RPC
    ///
    //////////////////////////////////////////////////////////////
    INVALID_PARAMS = -32602,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Internal error, error code defined by JSON RPC
    ///
    //////////////////////////////////////////////////////////////
    INTERNAL_ERROR = -32603,
};

} // namespace justanlsp