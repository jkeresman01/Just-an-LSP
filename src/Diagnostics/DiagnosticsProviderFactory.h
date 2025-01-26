#pragma once

#include <memory>

#include "FakeDiagnosticsProvider.h"
#include "IDiagnosticsProvider.h"
#include "../Config/ConfigurationManager.h"

namespace justanlsp
{
class DiagnosticsProviderFactory
{
  public:
    DiagnosticsProviderFactory() = delete;

    static std::shared_ptr<IDiagnosticsProvider> create()
    {
        std::string diagnosticsProvider = ConfigurationManager::getInstance()->getProperty("diagnosticsProvider");

        if(diagnosticsProvider == "fake")
        {
            return std::make_shared<FakeDiagnosticsProvider>();
        }

        if(diagnosticsProvider == "clang")
        {
            return std::make_shared<ClangDiagnosticsProvider>();
        }

        return std::make_shared<FakeDiagnosticsProvider>();
    }
};
} // namespace justanlsp
