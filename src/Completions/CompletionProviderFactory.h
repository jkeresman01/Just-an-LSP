#pragma once

#include <memory>

#include "FakeCompletionProvider.h"
#include "../Config/ConfigurationManager.h"
#include "ICompletionProvider.h"

namespace justanlsp
{
class CompletionProviderFactory
{
  public:
    // delete constructor to prevent instantion
    CompletionProviderFactory() = delete;

    static std::shared_ptr<ICompletionProvider> create()
    {
        std::string completionProvider = ConfigurationManager::getInstance()->getProperty("completion");

        if(completionProvider == "fake")
        {
            return std::make_shared<FakeCompletionProvider>();
        }

        //TODO implement rest of the completion providers

        return std::make_shared<FakeCompletionProvider>();
    }
};
} // namespace justanlsp
