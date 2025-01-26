#pragma once

#include <memory>

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"
#include "FakeCodectionsProvider.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{
class CodeActionsProviderFactory
{
  public:
    CodeActionsProviderFactory() = delete;

    static std::shared_ptr<ICodeActionsProvider> create()
    {
        std::string codeActionProvider = ConfigurationManager::getInstance()->getProperty("codeActionProvider");

        JLSP_DEBUG(STR("Code action provider: %s", codeActionProvider.c_str()));

        if(codeActionProvider == "fake")
        {
            return std::make_shared<FakeCodeActionsProvider>();
        }

        //TODO implement rest of code action providers

        return std::make_shared<FakeCodeActionsProvider>();
    }
};
} // namespace justanlsp
