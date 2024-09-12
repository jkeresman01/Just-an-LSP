#pragma once

#include <optional>
#include <string>

#include "Message.h"
#include "ResponseError.h"

namespace justanlsp
{

class ResponseMessage : public Message
{
  public:
    class Builder;

    const std::string &getResult() const;
    const ResponseError &getResponseError() const;

  private:
    std::string m_result;
    ResponseError m_responseError;

    ResponseMessage(const std::string &jsonRPC, const std::string &result,
                    const ResponseError &responseError);
};

class ResponseMessage::Builder
{
  public:
    ResponseMessage build() const;

    Builder &withJsonRPC(const std::string &jsonRPC);
    Builder &withResult(const std::string &result);
    Builder &withResponseError(const ResponseError &responseError);

  private:
    std::string m_jsonRPC;
    std::string m_result;
    ResponseError m_responseError;
};

} // namespace justanlsp
