#pragma once

#include <string>

#include "../Types/Range.h"

namespace justanlsp
{
class CodeActionParams
{
  public:
    explicit CodeActionParams(const nlohmann::json &jsonRPC);

    Range getRange() const { return m_range; };
    std::string getURI() const { return m_URI; };

  private:
    void setRange(const nlohmann::json &jsonRPC);
    void setStartPosition(const nlohmann::json &jsonRPC);
    void setEndPosition(const nlohmann::json &jsonRPC);
    void setURI(const nlohmann::json &jsonRPC);

  private:
    Range m_range;
    std::string m_URI;
};

} // namespace justanlsp
