#include "PredefinedSnipetProvider.h"
#include "SnippetRepositoryFactory.h"

namespace justanlsp
{
PredefinedSnippetProvider::PredefinedSnippetProvider()
{
    m_snippetRepository = SnippetRepositoryFactory::create();
}

// TODO refactor -- to much stuff going on in here
std::vector<CompletionItem> PredefinedSnippetProvider::getSnippets(const std::string &prefix)
{
    // TODO validate prefix

    m_snippets = m_snippetRepository.load();

    std::vector<std::string> snippets;
    auto range = snippets.equal_range(prefix);

    for (auto it = range.first; it != range.second; ++it)
    {
        snippets.push_back(it->second);
    }

    return getCompletionItems(snippets, prefix);
}

std::vector<CompletionItem> PredefinedSnippetProvider::getCompletions(
    const std::vector<std::string> &snippets, const std::string &prefix)
{
    std::vector<CompletionItem> completionItems(snippets.size());

    for (size_t i = 0; i < completionItems.size(); ++i)
    {
        completionItems.emplace_back(prefix, "", "", CompletionItemKind::SNIPPET, snippets[i]);
    }

    return completionItems;
}
} // namespace justanlsp
