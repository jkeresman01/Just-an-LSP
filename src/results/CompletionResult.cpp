#include "CompletionResult.h"

namespace justanlsp
{

CompletionResult::CompletionResult(const std::vector<CompletionItem> &completionItems)
    : m_completionItems(completionItems)
{
}

nlohmann::json CompletionResult::toJson() const
{
    std::vector<nlohmann::json> completions;

    for (const auto &completionItem : m_completionItems)
    {
        completions.push_back(completionItem.toJson());
    }

    return completions;
}

} // namespace justanlsp
