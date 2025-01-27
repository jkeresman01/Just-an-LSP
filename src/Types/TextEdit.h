#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "Range.h"

namespace justanlsp
{
class TextEdit
{
  public:
    TextEdit(const Range &range, const std::string &newText) : m_range(range), m_newText(newText){};

    nlohmann::json toJson() const { return {{"range", m_range.toJson()}, {"newText", m_newText}}; };

    std::string toString() const
    {
        std::stringstream ss;

        ss << "Range: " << m_range.toString() << "\r\n";
        ss << "TextEdit: " << m_newText << "\r\n";

        return ss.str();
    }

  private:
    Range m_range;
    std::string m_newText;
};
} // namespace justanlsp
