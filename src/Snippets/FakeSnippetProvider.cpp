#include "FakeSnippetProvider.h"

#include "../Types/CompletionItem.h"

#include <vector>

namespace justanlsp
{

std::vector<CompletionItem> FakeSnippetsProvider::getSnippets(const std::string &prefix)
{
    std::vector<CompletionItem> snippets;
    fillFakeSnippets(snippets);
    return snippets;
}

void fillFakeSnippets(std::vector<CompletionItem> &snippets)
{
    snippets.emplace_back();
}
} // namespace justanlsp
