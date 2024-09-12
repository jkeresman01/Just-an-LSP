#pragma once

#include <optional>
#include <string>

#include "ErrorCodes.h"

namespace justanlsp
{

class ResponseError
{
  public:
    ResponseError(ErrorCode code, const std::string &message);

    void setData(const std::string &data);

  private:
    ErrorCode m_code;
    std::string m_message;
    std::optional<std::string> m_data;
};

} // namespace justanlsp
