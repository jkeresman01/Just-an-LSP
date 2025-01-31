#pragma once

#include <memory>

#include "ISnippetRepository.h"
#include "SnippetRepository.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class SnippetRepositoryFactory
///
/// @brief Factory class for creating instances of ISnippetRepository.
///
/// @note This factory ensures that SnippetRepository instances are created
///       in a standardized way, allowing for easy dependency injection and
///       future extension.
///
//////////////////////////////////////////////////////////////
class SnippetRepositoryFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    SnippetRepositoryFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates a shared pointer to an instance of ISnippetRepository.
    ///
    /// @return A shared pointer to a newly created SnippetRepository instance.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ISnippetRepository> create() { return std::make_shared<SnippetRepository>(); }
};
} // namespace justanlsp
