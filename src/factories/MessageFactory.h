#pragma once

#include <memory>

#include "../enums/RequestType.h"
#include "../messages/InitializeRequest.h"
#include "../messages/RequestMessage.h"
#include "../messages/ShutdownRequest.h"

namespace justanlsp
{
class MessageFactory
{
  public:
    MessageFactory() = delete;

    static std::unique_ptr<RequestMessage> create(const RequestType &requestType,
                                                  const nlohmann::json &jsonRPC)
    {
        switch (requestType)
        {
        case RequestType::INITIALIZE:
            return std::make_unique<InitializeRequest>(jsonRPC);
        case RequestType::SHUTDOWN:
            return std::make_unique<ShutdownRequest>(jsonRPC);
        case RequestType::INITIALIZED:
            // TODO create initialized request
        case RequestType::TEXT_DOCUMENT_HOVER:
            // TODO create text document hover req
        case RequestType::TEXT_DOCUMENT_DID_OPEN:
            // TODO create text document did open req
        case RequestType::TEXT_DOCUMENT_DID_CHANGE:
            // TODO create text document did change req
        default:
            throw std::invalid_argument("Unknown LSP request type");
        }
    }
};
} // namespace justanlsp
