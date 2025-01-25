#pragma once

#include "../Types/Diagnostic.h"
#include "../Types/Position.h"
#include <string>
#include <vector>

namespace justanlsp
{
class IDiagnosticsProvider
{
  public:
    virtual std::vector<Diagnostic> getDiagnostics(const std::string &document, const Position &position) = 0;
};
} // namespace justanlsp
