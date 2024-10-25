#include "ResponseError.h"

#include <sstream>

namespace justanlsp
{

ResponseError::ResponseError(const ErrorCodes &code, const std::string &message)
    : m_code(code), m_message(message)
{

}

std::string ResponseError::toString() const
{
    std::stringstream ss;
    ss << "Error code { " << int(m_code) << " }, ";
    ss << "Error msg { " << m_message << " }, ";
    return ss.str();
}

} // namespace justanlsp
