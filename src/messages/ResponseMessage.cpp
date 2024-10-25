#include "ResponseMessage.h"

namespace justanlsp
{
#include "ResponseMessage.h"

ResponseMessage::ResponseMessage(const std::string &jsonRPC, const std::string &result,
                                 const ResponseError &responseError)
    : Message(jsonRPC), m_result(result), m_responseError(responseError)
{
}

const std::string &ResponseMessage::getResult() const
{
    return m_result;
}

const ResponseError &ResponseMessage::getResponseError() const
{
    return m_responseError;
}

ResponseMessage ResponseMessage::Builder::build() const
{
    return ResponseMessage(m_jsonRPC, m_result, m_responseError);
}

ResponseMessage::Builder &ResponseMessage::Builder::withJsonRPC(const std::string &jsonRPC)
{
    m_jsonRPC = jsonRPC;
    return *this;
}

ResponseMessage::Builder &ResponseMessage::Builder::withResult(const std::string &result)
{
    m_result = result;
    return *this;
}

ResponseMessage::Builder &ResponseMessage::Builder::withResponseError(const ResponseError &responseError)
{
    m_responseError = responseError;
    return *this;
}

} // namespace justanlsp
