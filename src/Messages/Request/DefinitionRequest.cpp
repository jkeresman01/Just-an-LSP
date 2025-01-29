#include "DefinitionRequest.h"

#include "../../Utils/Logger.h"

namespace justanlsp
{
DefintionRequest::DefintionRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DefintionRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("No params in textDocument/definition request");
        return;
    }

    m_hoverParams = std::make_shared<DefinitionParams>(jsonRPC["params"]);
}

} // namespace justanlsp
