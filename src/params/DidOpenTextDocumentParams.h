#pragma once

#include "../types/TextDocumentItem.h"

namespace justanlsp
{
class DidOpenTextDocumentParams
{
  public:
      DidOpenTextDocumentParams(const nlohamnn::json &jsonRPC);

      nlohmann::json toJson() const;

  private:
    TextDocumentItem m_textDocumentItem;
};
} // namespace justanlsp
