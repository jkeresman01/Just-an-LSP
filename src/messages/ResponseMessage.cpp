#include "ResponseMessage.h"

namespace justanlsp
{

ResponseMessage::ResponseMessage(const std::string &jsonRpc, int64_t id) : Message(jsonRpc), m_id(id){};

ResponseMessage::ResponseMessage(const std::string &jsonRpc, const int64_t id,
                                 const ResponseError &responseError)
    : Message(jsonRpc), m_id(id), m_responseError(responseError){};

nlohmann::json ResponseMessage::toJson() const
{
    nlohmann::json result = {{"jsonrpc", m_jsonRPC}, {"id", m_id}};

    if (m_responseError)
    {
        result["error"] = m_responseError->toJson();
    }

    return result;
}
} // namespace justanlsp
