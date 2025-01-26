#pragma once

#include <nlohmann/json.hpp>
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

    nlohmann::json toJson() const
    {
        nlohmann::json json;

        json["title"] = m_title;
        json["kind"] = m_codeActionKind;
        json["isPreffered"] = m_isPreffered;
        json["edit"] = m_workspaceEdit.toJson();

        return json;
    }

    class Builder
    {
      public:
        Builder &withTitle(const std::string &title)
        {
            m_title = title;
            return *this;
        }

        Builder &withCodeActionKind(const CodeActionKind &codeActionKind)
        {
            m_codeActionKind = codeActionKind;
            return *this;
        }

        Builder &withPrefferedFix(bool isPreffered)
        {
            m_isPreffered = isPreffered;
            return *this;
        }

        Builder &withWorkspaceEdit(const WorkspaceEdit &workspaceEdit)
        {
            m_workspaceEdit = workspaceEdit;
            return *this;
        }

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
