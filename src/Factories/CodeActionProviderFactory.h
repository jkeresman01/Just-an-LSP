#pragma once

#include "../CodeActions/FakeCodectionsProvider.h"
#include "../CodeActions/ICodeActionsProvider.h"
#include <memory>

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
