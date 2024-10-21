#pragma once

#include <optional>
#include <string>

#include "../errors/ErrorCodes.h"

namespace justanlsp
{

class ResponseError
{
  public:
    ResponseError(const ErrorCodes &code, const std::string &message);

    void setData(const std::string &data) { m_data = data; };

  private:
    ErrorCodes m_code;
    std::string m_message;
    std::optional<std::string> m_data;
};

} // namespace justanlsp
