#pragma once

#include <cstdint>

namespace lsp
{

enum class ErrorCodes : int32_t
{
    PARSE_ERROR       =  -32700,
    INVALID_REQUEST   =  -32600,
    METHOD_NOT_FOUND  =  -31601,
    INVALID_PARAMS    =  -32602,
    INTERNAL_ERROR    =  -32603,
};

} // lsp
