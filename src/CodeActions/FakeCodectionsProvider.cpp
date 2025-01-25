#include "FakeCodectionsProvider.h"

#include <vector>

namespace justanlsp
{
std::vector<CodeAction> FakeCodeActionsProvider::getCodeActions()
{
    std::vector<CodeAction> codeActions;
    fillFakeCodeActions(codeActions);
    return codeActions;
}

void FakeCodeActionsProvider::fillFakeCodeActions(std::vector<CodeAction> &codeActions)
{
    // TODO fill fake code actions
}

} // namespace justanlsp
