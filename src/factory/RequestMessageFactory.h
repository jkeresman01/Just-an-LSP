#pragma once

#include <memory>

#include "../enums/RequestType.h"
#include "../messages/InitializeRequest.h"
#include "../messages/RequestMessage.h"

namespace justanlsp
{
class RequestMessageFactory
{
  public:
      RequestMessageFactory() = delete;

    static std::unique_ptr<RequestMessage> create(const RequestType &requestType,
                                                  const nlohmann::json &jsonRPC)
    {
        switch (requestType)
        {
        case RequestType::INITIALIZE:
            return std::make_unique<InitializeRequest>(jsonRPC);
        case RequestType::INITIALIZED:
            // TODO create initialized request
            break;
        case RequestType::TEXT_DOCUMENT_HOVER:
            // TODO create text document hover req
            break;
        case RequestType::TEXT_DOCUMENT_DID_OPEN:
            // TODO create text document did open req
            break;

        case RequestType::TEXT_DOCUMENT_DID_CHANGE:
            // TODO create text document did change req
            break;
        default:
            throw std::invalid_argument("Unknown LSP request type");
        }
    }
};
} // namespace justanlsp
