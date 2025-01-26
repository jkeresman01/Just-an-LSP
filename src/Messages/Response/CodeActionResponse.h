#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../../Results/CodeActionResult.h"
#include "ResponseMessage.h"

namespace justanlsp
{
class CodeActionResponse : public ResponseMessage
{
  public:
    CodeActionResponse(const std::string &jsonRPC, const int64_t id,
                       const CodeActionResult &codeActionResult);

    nlohmann::json toJson() const;

    friend std::ostream &operator<<(std::ostream &os, const CodeActionResponse &codeActionResponse);

  private:
    CodeActionResult m_codeActionResult;
};
} // namespace justanlsp
