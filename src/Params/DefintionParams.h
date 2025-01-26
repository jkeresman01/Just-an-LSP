#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
{
class DefinitionParams : public TextDocumentPositionParams
{
  public:
    explicit DefinitionParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};
} // namespace justanlsp
