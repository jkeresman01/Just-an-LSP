#pragma once

#include <memory>

#include "FakeCompletionProvider.h"
#include "ICompletionProvider.h"

namespace justanlsp
{
class CompletionProviderFactory
{
  public:
    // delete constructor to prevent instantion
    CompletionProviderFactory() = delete;

    static std::shared_ptr<ICompletionProvider> create()
    {
        return std::make_shared<FakeCompletionProvider>();
    }
};
} // namespace justanlsp
