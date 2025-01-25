#pragma once

#include <memory>

#include "../Diagnostics/FakeDiagnosticsProvider.h"
#include "../Diagnostics/IDiagnosticsProvider.h"

namespace justanlsp
{
class DiagnosticsProviderFactory
{
  public:
    DiagnosticsProviderFactory() = delete;

    static std::shared_ptr<IDiagnosticsProvider> create()
    {
        return std::make_shared<FakeDiagnosticsProvider>();
    }
};
} // namespace justanlsp
