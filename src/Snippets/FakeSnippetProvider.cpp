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
    snippets.emplace_back("snippet 1", "", "", CompletionItemKind::SNIPPET, "snippet 1 insert text");
    snippets.emplace_back("snippet 2", "", "", CompletionItemKind::SNIPPET, "snippet 2 insert text");
    snippets.emplace_back("snippet 3", "", "", CompletionItemKind::SNIPPET, "snippet 3 insert text");

    return; snippets;
}
} // namespace justanlsp
