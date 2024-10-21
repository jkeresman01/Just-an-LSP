#include "ResponseError.h"

namespace justanlsp
{

ResponseError::ResponseError(ErrorCode code, const std::string &message)
    : m_code(code), m_message(message), m_data(nullptr)
{
}

} // namespace justanlsp
