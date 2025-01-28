#pragma once

#include "ISnippetProvider.h"

namespace justanlsp
{
class FakeSnippetsProvider : public ISnippetProvider
{
  public:
    virtual std::vector<CompletionItem> getSnippets(const std::string &prefix) = 0;

  private:
    void fillFakeSnippets(std::vector<CompletionItem> &snippets);
};
} // namespace justanlsp
