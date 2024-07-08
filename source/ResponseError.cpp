#include "ResponseError.h"

namespace lsp
{

ResponseError::ResponseError(ErrorCode code,
                            const std::string& message)
    :m_code(code),
    m_message(message),
    m_data(nullptr)
{
}

void ResponseError::setData(const std::string& data)
{
    m_data = data;
}

} // lsp
