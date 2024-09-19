#include "headers/ResponseMessage.h"

namespace justanlsp
{

ResponseMessage::ResponseMessage(const std::string &jsonRPC, const std::string &result,
                                 const ResponseError &responseError)
    : Message(jsonRPC), m_result(result), m_responseError(responseError)
{
}

} // namespace justanlsp
