#pragma once

#include <string>

#include "../errors/ErrorCodes.h"

namespace justanlsp
{

class ResponseError
{
  public:
    ResponseError(const ErrorCodes &code, const std::string &message);

  private:
    ErrorCodes m_code;
    std::string m_message;
};

} // namespace justanlsp
