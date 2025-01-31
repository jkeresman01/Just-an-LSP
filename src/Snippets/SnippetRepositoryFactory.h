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
//////////////////////////////////////////////////////////////
class SnippetRepositoryFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    SnippetRepositoryFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of ISnippetRepository.
    ///
    /// @return A shared pointer to a newly created
    ///         SnippetRepository instance.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ISnippetRepository> create() { return std::make_shared<SnippetRepository>(); }
};
} // namespace justanlsp
