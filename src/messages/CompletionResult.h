#pragma once

#include <vector>

#include "../types/CompletionItem.h"

namespace justanlsp
{
class CompletionResult
{
  public:
    CompletionResult(const std::vector<CompletionItem> &completionItem) : m_completionItems(completionItem){};

    nlohmann::json toJson() const
    {
        std::vector<nlohmann::json> comletions;

        for (const auto &completionItem : m_completionItems)
        {
            comletions.push_back(completionItem.toJson());
        }

        return comletions;
    }

  private:
    std::vector<CompletionItem> m_completionItems;
};
} // namespace justanlsp
