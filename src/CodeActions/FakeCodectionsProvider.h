#pragma once

#include "../Types/CodeAction.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{
class FakeCodeActionsProvider : public ICodeActionsProvider
{
  public:
    std::vector<CodeAction> getCodeActions() override;

  private:
    void fillFakeCodeActions(std::vector<CodeAction> &codeActions);
};
} // namespace justanlsp
