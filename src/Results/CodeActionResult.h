#pragma once

#include <vector>

#include "../Types/CodeAction.h"
#include <nlohmann/json.hpp>

namespace justanlsp
{
class CodeActionResult
{
  public:
    CodeActionResult(const std::vector<CodeAction> &codeActions) : m_codeActions(codeActions){};

    nlohmann::json toJson() const;

  private:
    std::vector<CodeAction> m_codeActions;
};
} // namespace justanlsp
