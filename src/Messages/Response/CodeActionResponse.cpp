#include "CodeActionResponse.h"

namespace justanlsp
{
CodeActionResponse::CodeActionResponse(const std::string &jsonRPC, const int64_t id,
                                       const CodeActionResult &codeActionResult)
    : ResponseMessage(jsonRPC, id), m_codeActionResult(codeActionResult)
{
}

nlohmann::json CodeActionResponse::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}, {"id", m_id}, {"result", m_codeActionResult.toJson()}};
}

std::ostream &operator<<(std::ostream &os, const CodeActionResponse &codeActionResponse)
{
    nlohmann::json jsonRPC = codeActionResponse.toJson();

    os << "Content-length: " << jsonRPC.dum(4).size() << "\r\n\r\n";
    os << jsonRPC.dump(4) << std::endl;

    return os;
}
} // namespace justanlsp
