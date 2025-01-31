#pragma once

#include "ISnippetRepository.h"
#include "SnippetRepository.h"

#include <map>
#include <memory>
#include <string>

namespace justanlsp
{
class SnippetRepositoryFactory
{
  public:
    SnippetRepositoryFactory() = default;

    static std::unique_ptr<ISnippetRepository> create() { return std::unique_ptr<SnippetRepository>(); }
};
} // namespace justanlsp
