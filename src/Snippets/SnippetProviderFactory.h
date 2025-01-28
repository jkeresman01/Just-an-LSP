#pragma once

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"
#include "FakeSnippetProvider.h"
#include "ISnippetProvider.h"

namespace justanlsp
{
class SnippetProviderFactory
{
  public:
    SnippetProviderFactory() = delete;

    static std::shared_ptr<ISnippetProvider> create()
    {
        std::string snippetsProvider = ConfigurationManager::getInstance()->getProperty("snippetsProvider");

        JLSP_DEBUG(STR("Snippets provder: %s", snippetsProvider.c_str()));

        if (snippetsProvider == "fake")
        {
            return std::make_shared<FakeSnippetsProvider>();
        }

        return std::make_shared<FakeSnippetsProvider>();
    }
};
} // namespace justanlsp
