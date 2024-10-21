#include "JustAnLSPFacade.h"

#include <memory>

#include "../enums/RequestType.h"
#include "../factory/RequestMessageFactory.h"
#include "../messages/InitializeRequest.h"
#include "../params/InitializeParams.h"
#include "../utils/Logger.h"
#include "../utils/RequestUtil.h"
#include "types/ClientInfo.h"

namespace justanlsp
{

ResponseMessage JustAnLSPFacade::handleRequest(const std::string &request)
{
    switch (RequestUtil::getRequestType(request))
    {
    case RequestType::INITIALIZE:
        return handleInitializeRequest(request);
    case RequestType::INITIALIZED:
        return handleInitializedRequest(request);
    case RequestType::TEXT_DOCUMENT_DID_OPEN:
        return handleTextDocumentDidOpenRequest(request);
    case RequestType::TEXT_DOCUMENT_DID_CHANGE:
        return handleTextDocumentDidChangeRequest(request);
    case RequestType::TEXT_DOCUMENT_HOVER:
        return handleTextDocumentHoverRequest(request);
    default:
        LOG_WARN << "Received request of unkown type";
        break;
    }
}

ResponseMessage JustAnLSPFacade::handleInitializeRequest(const std::string &request)
{
    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializeRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZE, jsonRPC);

    InitializeParams initializeParams = initializeRequest->getInitializeParams();
    ClientInfo clientInfo = initializeParams.getClientInfo();

    LOG_INFO << "Received initialize request from: " << clientInfo.toString();

    m_client->saveInfo(clientInfo);
    m_client->registerCapabilites(initializeParams.getClientCapabilites());

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleInitializedRequest(const std::string &request) {}

ResponseMessage JustAnLSPFacade::handleTextDocumentHoverRequest(const std::string &request)
{
    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializedRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZED, jsonRPC);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidOpenRequest(const std::string &request)
{
    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidChangeRequest(const std::string &request)
{
    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

} // namespace justanlsp
