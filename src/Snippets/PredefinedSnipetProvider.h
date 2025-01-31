#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ISnippetProvider.h"
#include "ISnippetRepository.h"

namespace justanlsp
{
typedef std::multimap<std::string, std::string> SnippetsT;

class PredefinedSnippetProvider : public ISnippetProvider
{
  public:
    PredefinedSnippetProvider();

    std::vector<CompletionItem> getSnippets(const std::string &prefix) override;

  private:
    std::vector<CompletionItem> getCompletions(const std::vector<std::string> &snippets,
                                               const std::string &prefix);

  private:
    SnippetsT m_snippets;
    std::unique_ptr<ISnippetRepository> m_snippetRepository;
};
} // namespace justanlsp
