#include "JustAnLSPFacade.h"

#include <memory>

#include "../enums/RequestType.h"
#include "../factories/RequestMessageFactory.h"
#include "../messages/InitializeRequest.h"
#include "../params/InitializeParams.h"
#include "../types/ClientInfo.h"
#include "../types/JustAnLSPClient.h"
#include "../utils/Logger.h"
#include "../utils/RequestUtil.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

ResponseMessage JustAnLSPFacade::handleRequest(const std::string &request)
{
    switch (RequestUtil::getType(request))
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
    LOG_INFO << "Proccessing initialize request";

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializeRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZE, jsonRPC);

    InitializeParams initializeParams = initializeRequest->getInitializeParams();

    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams.getClientCapabilites();
    ClientInfo clientInfo = initializeParams.getClientInfo();

    JustAnLSPClient client(clientInfo, clientCapabilities);

    LOG_INFO << "Received initialize request from: " << clientInfo.toString();

    JustAnLSPClientService::getInstance().registerClient(client);

    LOG_INFO << "Client has been successfully registered!";

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleInitializedRequest(const std::string &request)
{
    LOG_INFO << "Proccessing initialized request";

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializedRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZED, jsonRPC);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentHoverRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/Hover request";

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidOpenRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/DidOpen request";

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidChangeRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/DidChange request";

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

} // namespace justanlsp
