#pragma once

#include "../Types/CodeAction.h"

#include <vector>

namespace justanlsp
{
class ICodeActionsProvider
{
  public:
    virtual std::vector<CodeAction> getCodeActions() = 0;
};
} // namespace justanlsp
