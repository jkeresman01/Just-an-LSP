#pragma once


#include <vector>

namespace justanlsp
{
    class ICodeActionsProvider
    {
        public:
            //TODO => add code aciton type
            virtual std::vector<CodeAction> getCodeActions() = 0;
    };
}
