#include "HoverRequest.h"

#include "../../Utils/Logger.h"

namespace justanlsp
{
HoverRequest::HoverRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void HoverRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("No params in textDocument/hover request");
        return;
    }

    m_hoverParams = std::make_shared<HoverParams>(jsonRPC["params"]);
}

} // namespace justanlsp
