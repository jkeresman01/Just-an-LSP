#pragma once

#include "ISnippetProvider.h"
#include <string>
#include <vector>

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class FakeSnippetsProvider
///
/// @brief A mock implementation of ISnippetProvider that provides
///        predefined fake snippets for testing purposes.
///
//////////////////////////////////////////////////////////////
class FakeSnippetsProvider : public ISnippetProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of snippets that match the given prefix.
    ///
    /// @param prefix
    ///
    /// @return A vector of matching CompletionItems.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CompletionItem> getSnippets(const std::string &prefix) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Populates a vector with fake snippets.
    ///
    /// @param snippets
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeSnippets(std::vector<CompletionItem> &snippets);
};
} // namespace justanlsp
