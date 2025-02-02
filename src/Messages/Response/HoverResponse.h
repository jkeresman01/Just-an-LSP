#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../../Results/HoverResult.h/"
#include "ResponseMessage.h"

namespace justanlsp
{
class HoverResponse : public ResponseMessage
{
  public:
    HoverResponse(const std::string &jsonRPC, const int64_t id, const HoverResult &hoverResult);

    nlohmann::json toJson() const;

    friend std::ostream &operator<<(std::ostream &os, const CodeActionResponse &codeActionResponse);

  private:
    HoverResult m_hoverResult;
};
} // namespace justanlsp
