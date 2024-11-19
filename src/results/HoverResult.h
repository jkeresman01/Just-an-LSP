#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace justanlsp
{
class HoverResult
{
  public:
    HoverResult(const std::string &value) : m_value(value){};

    nlohmann::json toJson() const { return {{"result", m_value}}; };

  private:
    std::string m_value;
};
} // namespace justanlsp
