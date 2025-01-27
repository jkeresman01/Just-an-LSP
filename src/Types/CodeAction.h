#pragma once

#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

#include "../Enums/CodeActionKind.h"
#include "WorkspaceEdit.h"

namespace justanlsp
{
class CodeAction
{
  public:
    CodeAction() = delete;

    CodeAction(const std::string &title, const CodeActionKind &codeActionKind, const bool isPreffered,
               const WorkspaceEdit &edit){};

    std::string toString() const;

    nlohmann::json toJson() const;

    class Builder
    {
      public:
        Builder &withTitle(const std::string &title);

        Builder &withCodeActionKind(const CodeActionKind &codeActionKind);

        Builder &withPrefferedFix(bool isPreffered);

        Builder &withWorkspaceEdit(const WorkspaceEdit &workspaceEdit);

        CodeAction build();

      private:
        std::string m_title;
        CodeActionKind m_codeActionKind;
        bool m_isPreffered;
        WorkspaceEdit m_workspaceEdit;
    };

  private:
    std::string m_title;
    CodeActionKind m_codeActionKind;
    bool m_isPreffered;
    WorkspaceEdit m_workspaceEdit;
};
} // namespace justanlsp
