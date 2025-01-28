#include "FakeCodectionsProvider.h"

#include "../Types/CodeAction.h"
#include "../Types/Range.h"
#include "../Types/TextEdit.h"
#include "../Types/WorkspaceEdit.h"

#include <vector>

namespace justanlsp
{
std::vector<CodeAction> FakeCodeActionsProvider::getCodeActions(const std::string &URI)
{
    std::vector<CodeAction> codeActions;
    fillFakeCodeActions(codeActions, URI);
    return codeActions;
}

void FakeCodeActionsProvider::fillFakeCodeActions(std::vector<CodeAction> &codeActions,
                                                  const std::string &URI)
{
    WorkspaceEdit workspaceEdit;
    Range range{{4, 0}, {4, 10}};
    TextEdit textEdit(range, "New text");

    workspaceEdit.changes[URI].push_back(textEdit);
    codeActions.emplace_back("Code action test", CodeActionKind::QUICK_FIX, false, workspaceEdit);
    codeActions.emplace_back("Code action test 1", CodeActionKind::QUICK_FIX, false, workspaceEdit);
    codeActions.emplace_back("Code action test 2", CodeActionKind::QUICK_FIX, false, workspaceEdit);
}

} // namespace justanlsp
