#pragma once

#include <nlohmann/json.hpp>

#include "../types/Position.h"
#include "../types/TextDocumentIdentifier.h"

namespace justanlsp
{
class TextDocumentPositionParams
{
  public:
    TextDocumentPositionParams(const nlohmann::json &jsonRPC);

  private:
    void setTextDocumentIdentifier(const nlohmann::json &jsonRPC);
    void setPostion(const nlohmann::json &jsonRPC);

  private:
    TextDocumentIdentifier m_textDocument;
    Position m_position;
};
} // namespace justanlsp
