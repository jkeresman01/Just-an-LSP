#pragma once

#include <string>

#include "../types/TextDocumentIdentifier.h"

namespace justanlsp
{
class DidChangeTextDocumenParams
{
  public:
    DidChangeTextDocumenParams(const std::nlohamnn::json &jsonRPC);

  private:
    void setTextDocumentIdentifier(const std::nlohamnn::json &jsonRPC);

    void setContentChanges(const std::nlohamnn::json &jsonRPC);

  private:
    TextDocumentIdentifier m_textDocument;
    std::string m_contentChanges;
};
} // namespace justanlsp
