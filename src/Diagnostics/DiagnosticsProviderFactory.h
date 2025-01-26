#pragma once

#include <memory>

#include "FakeDiagnosticsProvider.h"
#include "ClangDiagnosticsProvider.h"
#include "IDiagnosticsProvider.h"

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"

namespace justanlsp
{
class DiagnosticsProviderFactory
{
  public:
    DiagnosticsProviderFactory() = delete;

    static std::shared_ptr<IDiagnosticsProvider> create()
    {
        std::string diagnosticsProvider = ConfigurationManager::getInstance()->getProperty("diagnosticsProvider");

        JLSP_DEBUG(STR("Diagnostics provder: %s", diagnosticsProvider.c_str()));

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
