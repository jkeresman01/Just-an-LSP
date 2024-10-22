#include "JustAnLSPFacade.h"

#include <memory>

#include "../enums/RequestType.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../factories/MessageFactory.h"
#include "../messages/InitializeRequest.h"
#include "../messages/InitializeResponse.h"
#include "../params/InitializeParams.h"
#include "../rpc/Rpc.h"
#include "../types/ClientInfo.h"
#include "../types/JustAnLSPClient.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

ResponseMessage JustAnLSPFacade::handleRequest(const std::string &request)
{
    switch (MessageUtil::getType(request))
    {
    case RequestType::INITIALIZE:
        handleInitializeRequest(request);
        break;
    case RequestType::INITIALIZED:
        handleInitializedRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_OPEN:
        handleTextDocumentDidOpenRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_CHANGE:
        handleTextDocumentDidChangeRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_HOVER:
        handleTextDocumentHoverRequest(request);
        break;
    default:
        LOG_WARN << "Received request of unkown type";
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const std::string &request)
{
    LOG_INFO << "Proccessing initialize request";

    m_justAnLspCounters->increment(RequestType::INITIALIZE);
    if (m_justAnLspCounters->getValue(RequestType::INITIALIZE) != 1)
    {
        LOG_ERROR << "Initialize request should be the first that is send from client to JustAnLSP server!";
        // TODO send response with erorr code SERVER_NOT_INITIALIZED = -32002,
    }

    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
    std::unique_ptr<InitializeRequest> initializeRequest =
        MessageFactory::create(RequestType::INITIALIZE, jsonRPC);

    InitializeParams initializeParams = initializeRequest->getInitializeParams();

    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams.getClientCapabilites();
    m_justAnLSPClient->registerCapabilities(clientCapabilities);

    ClientInfo clientInfo = initializeParams.getClientInfo();
    m_justAnLSPClient->saveInfo(clientInfo);

    LOG_INFO << "Received initialization request from " << m_justAnLSPClient.toString();

    InitializeResponse initializeResponse({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});

    Rpc::send(initializeResponse);
}

void JustAnLSPFacade::handleInitializedRequest(const std::string &request)
{
    LOG_INFO << "Proccessing initialized request";

    m_justAnLspCounters->increment(RequestType::INITIALIZED);
    if (m_justAnLspCounters.getValue(RequestType::INITIALIZED) != 1 and m_justAnLspCounters.getSum() != 2)
    {
        LOG_ERROR << "Initialied request should should be first one after Initialize request";
    }

    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
    std::unique_ptr<InitializedRequest> initializeRequest =
        MessageFactory::create(RequestType::INITIALIZED, jsonRPC);

    // TODO basic response
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/hover request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
}

void JustAnLSPFacade::handleTextDocumentDidOpenRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/didOpen request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    nlohmann::json jsonRPC = MessageUtil::tryParse(request);

    // TODO basic response
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const std::string &request)
{
    LOG_INFO << "Proccessing textDocument/didChange request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    nlohmann::json jsonRPC = MessageUtil::tryParse(request);

    // TODO basic response
}

} // namespace justanlsp
