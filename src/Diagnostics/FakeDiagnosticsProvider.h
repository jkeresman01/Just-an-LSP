#pragma once

#include <vector>

#include "../Types/Diagnostic.h"
#include "IDiagnosticsProvider.h"

namespace justanlsp
{
class FakeDiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    FakeDiagnosticsProvider() = default;

    std::vector<Diagnostic> getDiagnostics(const std::string &document, const Position &position) override;

  private:
    void fillFakeDiagnostics(std::vector<Diagnostic> &diagnostics);
};
} // namespace justanlsp
