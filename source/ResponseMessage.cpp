#include "ResponseMessage.h"

namespace lsp
{

ResponseMessage::ResponseMessage(const std::string &jsonRPC,
                                 const std::optional<std::string>& result,
                                 const std::optional<ResponseError>& responseError)
    : Message(jsonRPC),
    m_result(result),
    m_responseError(responseError) 
{
}

ResponseMessage::Builder& ResponseMessage::Builder::withJsonRPC(const std::string& jsonRPC)
{
    m_jsonRPC = jsonRPC;
    return *this;
}

ResponseMessage::Builder& ResponseMessage::Builder::withResult(const std::optional<std::string>& result)
{
    m_result = result;
    return *this;
}

ResponseMessage::Builder& ResponseMessage::Builder::withResponseError(const std::optional<ResponseError>& responseError)
{
    m_responseError = responseError;
    return *this;
}

ResponseMessage ResponseMessage::Builder::build() const
{
    return ResponseMessage(m_jsonRPC, m_result, m_responseError);
}

} // namespace lsp

