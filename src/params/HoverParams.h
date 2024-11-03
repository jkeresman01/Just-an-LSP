#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
{
class HoverParams : public TextDocumentPositionParams
{
  public:
    explicit HoverParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};
} // namespace justanlsp
