#pragma once

#include "ICodeActionsProvider.h"

namespace justanlsp
{
    class FakeCodeActionsProvider : public ICodeActionsProvider 
    {
        public:
            std::vector<CodeAction> getCodeActions() override;

        private:
            void fillFakeCodeActions(std::vector<CodeAction> &codeActions);
    };
}
