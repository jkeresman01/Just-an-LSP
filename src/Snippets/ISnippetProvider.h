#pragma once

#include "../Types/CompletionItem.h"

#include <string>
#include <vector>

namespace justanlsp
{
class ISnippetProvider
{
  public:
    virtual std::vector<CompletionItem> getSnippets(const std::string &prefix) = 0;
};
} // namespace justanlsp
