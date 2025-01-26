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

  private:
    Range m_range;
    std::string m_newText;
};
} // namespace justanlsp
