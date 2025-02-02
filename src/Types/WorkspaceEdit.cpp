#include "WorkspaceEdit.h"

#include <nlohmann/json.hpp>

namespace justanlsp
{

void WorkspaceEdit::addChage(const std::pair<std::string, std::vector<TextEdit>> &textEdit) const
{
    m_changes.insert(textEdit);
}

nlohmann::json WorkspaceEdit::toJson() const
{
    nlohmann::json json;

    for (const auto &[URI, edits] : changes)
    {
        nlohmann::json jsonEdits = nlohmann::json::array();

        for (const auto &edit : edits)
        {
            jsonEdits.push_back(edit.toJson());
        }

        json["changes"][URI] = jsonEdits;
    }

    return json;
}

std::string WorkspaceEdit::toString() const
{
    std::stringstream ss;

    for (const auto &[URI, edits] : changes)
    {
        for (const auto &edit : edits)
        {
            ss << "[" << URI << "]"
               << " : " << edit.toString() << "\r\n";
        }
    }

    return ss.str();
}

} // namespace justanlsp
