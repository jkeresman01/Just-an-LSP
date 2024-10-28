#pragma once

#include <string>
#include <vector>

#include "../types/Diagnostic.h"

namespace justanlsp
{
class PublishDiagnosticsParams
{
  public:
    // TODO It's self explanatory what I need to do here

  private:
    std::string m_URI;
    std::vector<Diagnostic> m_diagnostics;
};
} // namespace justanlsp
