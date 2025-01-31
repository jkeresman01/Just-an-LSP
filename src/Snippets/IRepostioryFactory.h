#pragma once

#include <memory>

#include "ISnippetRepository.h"
#include "SnippetRepository.h"

namespace justanlsp
{
class SnippetRepositoryFactory
{
  public:
    SnippetRepositoryFactory() = delete;

    static std::shared_ptr<ISnippetRepository> create() { return std::make_shared<SnippetRepository>(); }
};
} // namespace justanlsp
