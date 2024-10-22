#include "JustAnLSPFacade.h"

#include <memory>

#include "../enums/RequestType.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../factories/RequestMessageFactory.h"
#include "../messages/InitializeRequest.h"
#include "../messages/InitializeResponse.h"
#include "../params/InitializeParams.h"
#include "../types/ClientInfo.h"
#include "../types/JustAnLSPClient.h"
#include "../utils/Logger.h"
#include "../utils/RequestUtil.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

uint64_t JustAnLSPFacade::m_requestCounter = 0;

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

    m_justAnLspCounters->increment(RequestType::INITIALIZE);
    if (m_justAnLspCounters->getValue(RequestType::INITIALIZE) != 1)
    {
        LOG_ERROR << "Initialize request should be the first that is send from client to JustAnLSP server!";
        // TODO return response with erorr code SERVER_NOT_INITIALIZED = -32002,
    }

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializeRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZE, jsonRPC);

    InitializeParams initializeParams = initializeRequest->getInitializeParams();

    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams.getClientCapabilites();
    ClientInfo clientInfo = initializeParams.getClientInfo();

    JustAnLSPClient client(clientInfo, clientCapabilities);

    LOG_INFO << "Received initialize request from: " << clientInfo.toString();

    JustAnLSPClientService::getInstance().registerClient(client);

    return InitializeResponse({"justAnLSP", "0.0.0.0.1-beta"}, {TextDocumentSyncKind::FULL});
}

ResponseMessage JustAnLSPFacade::handleInitializedRequest(const std::string &request)
{
    LOG_INFO << "Proccessing initialized request";

    m_justAnLspCounters->increment(RequestType::INITIALIZED);

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);
    std::unique_ptr<InitializedRequest> initializeRequest =
        RequestMessageFactory::create(RequestType::INITIALIZED, jsonRPC);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentHoverRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/hover request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidOpenRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/didOpen request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidChangeRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/didChange request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    nlohmann::json jsonRPC = RequestUtil::tryParse(request);

    // TODO basic response
}

} // namespace justanlsp
