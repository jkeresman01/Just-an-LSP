#pragma once

#include "../Types/CompletionItem.h"
#include <vector>

namespace justanlsp
{
class ICompletionProvider
{
  public:
    virtual std::vector<CompletionItem> getCompletions() = 0;
};
} // namespace justanlsp
