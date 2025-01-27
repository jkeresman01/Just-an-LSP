#pragma once

#include "../Types/CodeAction.h"

#include <vector>

namespace justanlsp
{
class ICodeActionsProvider
{
  public:
    virtual std::vector<CodeAction> getCodeActions(const std::string &URI) = 0;
};
} // namespace justanlsp
