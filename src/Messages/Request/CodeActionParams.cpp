#include "CodeActionRequest.h"

#include "../../Utils/Logger.h"

namespace justanlsp
{
CodeActionRequest::CodeActionRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void CodeActionRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        JLSP_ERROR("No textDocument/codeAction params in textDocument/codeAction request");
        return;
    }

    m_codeActionParams = std::make_shared<CodeActionParams>(jsonRPC["params"]);
}
} // namespace justanlsp
