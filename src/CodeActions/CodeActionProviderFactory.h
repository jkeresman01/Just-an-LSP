#pragma once

#include <memory>

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"
#include "FakeCodectionsProvider.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class CodeActionsProviderFactory
///
/// @brief Factory class to create instances of code actions
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class CodeActionsProviderFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    CodeActionsProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a code actions provider.
    ///
    /// @return A shared pointer to an instance of
    ///         a class implementing ICodeActionsProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ICodeActionsProvider> create()
    {
        std::string codeActionProvider =
            ConfigurationManager::getInstance()->getProperty("codeActionProvider");

        JLSP_DEBUG(STR("Code action provider: %s", codeActionProvider.c_str()));

        if (codeActionProvider == "fake")
        {
            return std::make_shared<FakeCodeActionsProvider>();
        }

        // TODO implement rest of code action providers

        return std::make_shared<FakeCodeActionsProvider>();
    }
};

} // namespace justanlsp
