#pragma once

#include <memory>
#include "../CodeActions/ICodeActionsProvider.h"
#include "../CodeActions/FakeCodectionsProvider.h"

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
}


