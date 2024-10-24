#include "ResponseError.h"

namespace justanlsp
{
ResponseError::ResponseError(const ErrorCodes &code, const std::string &message)
    : m_code(code), m_message(message)
{
}

} // namespace justanlsp
