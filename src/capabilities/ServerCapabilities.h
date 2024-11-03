#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

#include "../enums/TextDocumentSyncKind.h"

namespace justanlsp
{

typedef std::unordered_map<std::string, std::string> CompletionProviderT;

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilities
///
/// @brief ServerCapabilities ...
///
//////////////////////////////////////////////////////////////
class ServerCapabilities
{
    // TODO rest of the capilites (only text is provided for now)

  public:
    explicit ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind);

    nlohmann::json toJson() const;

  private:
    TextDocumentSyncKind m_textDocumentSyncKind;

    CompletionProviderT m_completionProvider;
};
} // namespace justanlsp
