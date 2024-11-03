#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../../params/HoverParams.h"
#include "RequestMessage.h"

namespace justanlsp
{
class HoverRequest : public RequestMessage
{
  public:
    explicit HoverRequest(const nlohmann::json &jsonRPC);

    std::shared_ptr<HoverParams> getParams() const { return m_hoverParams; };

  private:
    void setParams(const nlohmann::json &jsonRPC);

  private:
    std::shared_ptr<HoverParams> m_hoverParams;
};
} // namespace justanlsp
