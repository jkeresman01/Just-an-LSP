#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "CompletionResult.h"
#include "ResponseMessage.h"

namespace justanlsp
{
class CompletionResponse : public ResponseMessage
{
  public:
    CompletionResponse(const std::string &jsonRPC, int64_t &id, const CompletionResult &completionResult);

    nlohmann::json toJson() const;

  private:
    CompletionResult m_completionResult;
};
} // namespace justanlsp
