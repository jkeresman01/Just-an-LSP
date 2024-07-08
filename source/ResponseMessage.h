#pragma once

#include "Message.h"
#include "ResponseError.h"
#include <optional>
#include <string>

namespace lsp
{

class ResponseMessage : public Message
{
public:
    class Builder;

    const std::optional<std::string>& getResult() const;
    const std::optional<ResponseError>& getResponseError() const;

private:
    std::optional<std::string> m_result;
    std::optional<ResponseError> m_responseError;

    ResponseMessage(const std::string &jsonRPC, 
                    const std::optional<std::string>& result,
                    const std::optional<ResponseError>& responseError);
};

class ResponseMessage::Builder
{
public:
    ResponseMessage build() const;

    Builder& withJsonRPC(const std::string& jsonRPC);
    Builder& withResult(const std::optional<std::string>& result);
    Builder& withResponseError(const std::optional<ResponseError>& responseError);
    
    
private:
    std::string m_jsonRPC;
    std::optional<std::string> m_result;
    std::optional<ResponseError> m_responseError;
};

} // namespace lsp

