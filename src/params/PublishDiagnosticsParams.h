#pragma once

#include <string>
#include <vector>

#include "../types/Diagnostic.h"

namespace justanlsp
{
class PublishDiagnosticsParams
{
  public:
  private:
    std::string m_URI;
    std::vector<Diagnostic> m_diagnostics;
};
} // namespace justanlsp
