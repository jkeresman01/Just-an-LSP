#pragma once

#include <nlohmann/json.hpp>
#include <vector>

#include "../types/CompletionItem.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class CompletionResult
///
/// @brief Represents the result of a completion request, containing
///        a list of completion items that are potential code suggestions
///        or options for the client.
///
//////////////////////////////////////////////////////////////
class CompletionResult
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a CompletionResult with a provided vector of
    ///        completion items.
    ///
    /// @param completionItems
    ///
    //////////////////////////////////////////////////////////////
    CompletionResult(const std::vector<CompletionItem> &completionItems)
        : m_completionItems(completionItems){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the completion result to JSON format.
    ///
    /// @return Returns list of comletion options
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const
    {
        std::vector<nlohmann::json> completions;

        for (const auto &completionItem : m_completionItems)
        {
            completions.push_back(completionItem.toJson());
        }

        return completions;
    }

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Stores a list of completion items for a completion response.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CompletionItem> m_completionItems;
};

} // namespace justanlsp
