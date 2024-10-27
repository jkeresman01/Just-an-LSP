#include "CompletionResponse.h"

namespace justanlsp
{

CompletionResponse::CompletionResponse(const std::string &jsonRPC, int64_t &id,
                                       const CompletionResult &completionResult)
    : ResponseMessage(jsonRPC, id), m_completionResult(completionResult)
{
}

nlohmann::json CompletionResponse::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}, {"id", m_id}, {"result", m_completionResult.toJson()}};
}

} // namespace justanlsp
