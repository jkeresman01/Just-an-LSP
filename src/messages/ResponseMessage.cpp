#include "ResponseMessage.h"

namespace justanlsp
{
#include "ResponseMessage.h"

ResponseMessage::ResponseMessage(const std::string &jsonRPC, const ResponseError &responseError)
    : Message(jsonRPC), m_responseError(responseError)
{
}

const ResponseError &ResponseMessage::getResponseError() const
{
    return m_responseError;
}

ResponseMessage ResponseMessage::Builder::build() const
{
    return ResponseMessage(m_jsonRPC,  m_responseError);
}

ResponseMessage::Builder &ResponseMessage::Builder::withJsonRPC(const std::string &jsonRPC)
{
    m_jsonRPC = jsonRPC;
    return *this;
}

ResponseMessage::Builder &ResponseMessage::Builder::withResponseError(const ResponseError &responseError)
{
    m_responseError = responseError;
    return *this;
}

} // namespace justanlsp
