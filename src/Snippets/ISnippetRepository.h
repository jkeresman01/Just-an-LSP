#pragma once

#include <map>
#include <string>

namespace justanlsp
{
class ISnippetRepository
{
  public:
    virtual std::multimap<std::string, std::string> load() = 0;
};
} // namespace justanlsp
