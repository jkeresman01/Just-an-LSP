#pragma once

#include <memory>

#include "FakeCodectionsProvider.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{
class CodeActionsProviderFactory
{
  public:
    CodeActionsProviderFactory() = delete;

    static std::shared_ptr<ICodeActionsProvider> create()
    {
        return std::make_shared<FakeCodeActionsProvider>();
    }
};
} // namespace justanlsp
