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
            // TODO create initialize request
            break;
        case RequestType::TEXT_DOCUMENT_DID_OPEN:
            // TODO create text document did open
            break;

        case RequestType::TEXT_DOCUMENT_DID_CHANGE:
            // TODO create text document did change
            break;
        default:
            throw std::invalid_argument("Unknown LSP request type");
        }
    }
};
} // namespace justanlsp
