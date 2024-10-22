#pragma once

#include <string>

#include "../enums/RequestType.h"

namespace justanlsp
{
class RequestMethodUtil
{
  public:
    RequestMethodUtil() = delete;

    static RequestType getType(const std::string &method)
    {
        if (method == "initalize")
        {
            return RequestType::INITIALIZE;
        }
        if (method == "initalized")
        {
            return RequestType::INITIALIZED;
        }
        else if (method == "textDocument/didChange")
        {
            return RequestType::TEXT_DOCUMENT_DID_CHANGE;
        }
        else if (method == "textDocument/didOpen")
        {
            return RequestType::TEXT_DOCUMENT_DID_OPEN;
        }
        else if (method == "textDocumen/hover")
        {
            return RequestType::TEXT_DOCUMENT_HOVER;
        }
        else
        {
            return RequestType::UNKNOWN;
        }
    }
};
} // namespace justanlsp
