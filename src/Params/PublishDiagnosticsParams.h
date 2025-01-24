#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "../Types/Diagnostic.h"

namespace justanlsp
{
class PublishDiagnosticsParams
{
  public:
    PublishDiagnosticsParams(const std::string &URI, const std::vector<Diagnostic> &diagnostics);

    nlohmann::json toJson() const;

  private:
    nlohmann::json dianosticItemsToJson() const;

  private:
    std::string m_URI;
    std::vector<Diagnostic> m_diagnostics;
};
} // namespace justanlsp
