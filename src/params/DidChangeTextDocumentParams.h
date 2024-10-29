#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../types/TextDocumentIdentifier.h"

namespace justanlsp
{
class DidChangeTextDocumenParams
{
  public:
    DidChangeTextDocumenParams(const nlohmann::json &jsonRPC);

  private:
    void setTextDocumentIdentifier(const nlohmann::json &jsonRPC);

    void setContentChanges(const nlohmann::json &jsonRPC);

  private:
    TextDocumentIdentifier m_textDocument;
    std::string m_contentChanges;
};
} // namespace justanlsp
