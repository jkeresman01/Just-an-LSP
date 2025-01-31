#pragma once

#include <map>
#include <string>

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class ISnippetRepository
///
/// @brief Interface for a snippet repository that loads code snippets.
///
//////////////////////////////////////////////////////////////
class ISnippetRepository
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Virtual destructor to ensure proper cleanup
    ///        of derived classes.
    ///
    //////////////////////////////////////////////////////////////
    virtual ~ISnippetRepository() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads snippets from a source and returns them as a multimap.
    ///
    /// @return A multimap where the key is the snippet identifier, and
    ///         the value is the corresponding snippet code.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::multimap<std::string, std::string> load() = 0;
};
} // namespace justanlsp
