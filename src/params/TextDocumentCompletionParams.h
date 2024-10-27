#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
{
class TextDocumentCompletionParams : public TextDocumentPositionParams
{
  public:
    TextDocumentCompletionParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};
} // namespace justanlsp
