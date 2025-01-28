#pragma once

#include <memory>

#include "ClangDiagnosticsProvider.h"
#include "FakeDiagnosticsProvider.h"
#include "IDiagnosticsProvider.h"

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class DiagnosticsProviderFactory
///
/// @brief Factory class for creating instances of diagnostics
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class DiagnosticsProviderFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    DiagnosticsProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a diagnostics provider.
    ///
    /// @return A shared pointer to an instance of a class
    ///         implementing IDiagnosticsProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<IDiagnosticsProvider> create()
    {
        std::string diagnosticsProvider =
            ConfigurationManager::getInstance()->getProperty("diagnosticsProvider");

        JLSP_DEBUG(STR("Diagnostics provider: %s", diagnosticsProvider.c_str()));

        if (diagnosticsProvider == "fake")
        {
            return std::make_shared<FakeDiagnosticsProvider>();
        }

        if (diagnosticsProvider == "clang")
        {
            return std::make_shared<ClangDiagnosticsProvider>();
        }

        // Default to FakeDiagnosticsProvider if no valid configuration is found.
        return std::make_shared<FakeDiagnosticsProvider>();
    }
};

} // namespace justanlsp
