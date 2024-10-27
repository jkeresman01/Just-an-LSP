#pragma once

#include <string>

namespace justanlsp
{
struct CompletionItem
{
    std::string label;
    std::string detail;
    std::string documentation;

    nlohmann::json toJson() const
    {
        return {{"label", label}, {"detail", detail}, {"documentation", documentation}};
    }
};
} // namespace justanlsp
