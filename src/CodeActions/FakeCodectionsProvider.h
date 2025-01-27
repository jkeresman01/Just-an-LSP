#pragma once

#include "../Types/CodeAction.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{
class FakeCodeActionsProvider : public ICodeActionsProvider
{
  public:
    std::vector<CodeAction> getCodeActions(const std::string &URI) override;

  private:
    void fillFakeCodeActions(std::vector<CodeAction> &codeAction, const std::string &URI);

    void logCodeActions(std::vector<CodeAction> &codeAction);
};
} // namespace justanlsp
