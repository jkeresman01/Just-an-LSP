#pragma once

#include "../Types/CompletionItem.h"
#include "ICompletionProvider.h"

#include <vector>

namespace justanlsp
{
class FakeCompletionProvider : public ICompletionProvider
{
  public:
    std::vector<CompletionItem> getCompletions() override;

  private:
    void fillFakeComletions(std::vector<CompletionItem> &completions);
};
} // namespace justanlsp
