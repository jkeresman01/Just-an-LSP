#pragma once

#include "TextEdit.h"

#include <nlohmann/json.hpp>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace justanlsp
{
typedef std::unordered_map<std::string, std::vector<TextEdit>> ChangesT;

struct WorkspaceEdit
{
    ChangesT changes;

    nlohmann::json toJson() const
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

    std::string toString() const
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
};
} // namespace justanlsp
