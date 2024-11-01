#include "JustAnLSPFacade.h"
#include "JustAnLSPServer.h"

#include <iostream>
#include <memory>
#include <vector>

#include "../enums/RequestType.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../factories/MessageFactory.h"
#include "../messages/request/DidChangeTextDocumentRequest.h"
#include "../messages/request/ShutdownRequest.h"
#include "../messages/response/CompletionResponse.h"
#include "../messages/response/ResponseMessage.h"
#include "../params/InitializeParams.h"
#include "../rpc/Rpc.h"
#include "../types/ClientInfo.h"
#include "../types/CompletionItem.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"
#include "JUstAnLSPClientService.h"
#include "JustAnLSPClient.h"
#include "JustAnLSPCounter.h"
#include "JustAnLSPErrorHandler.h"
#include "JustAnLSPServer.h"

namespace justanlsp
{

void JustAnLSPFacade::handleRequest(const nlohmann::json &request)
{
    switch (MessageUtil::getType(request))
    {
    case RequestType::INITIALIZE:
        handleInitializeRequest(request);
        break;
    case RequestType::SHUTDOWN:
        handleShutdownRequest(request);
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
    case RequestType::TEXT_DOCUMENT_COMPLETION:
        handleTextDocumentCompletionRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_HOVER:
        handleTextDocumentHoverRequest(request);
        break;
    default:
        LOG_ERROR("Received request/notification with method: UNKNOWN_TYPE");
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Prcoessing request with method: initialize");

    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(jsonRPC);

    m_justAnLSPReqHandler->initializeReq(initializeRequest);
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with method: shutdown");

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    std::shared_ptr<ShutdownRequest> shutdownRequest = MessageFactory::createShutdownReq(jsonRPC);

    m_justAnLSPReqHandler->shutdownReq(shutdownRequest);
}

void JustAnLSPFacade::handleInitializedRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received notification with method: initialized");

    m_justAnLspCounters->increment(RequestType::INITIALIZED);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    LOG_INFO("Successful connection between client and JustAnLSPServer has been established");
}

void JustAnLSPFacade::handleTextDocumentDidOpenRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received notification with method: textDocument/didOpen");

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<DidOpenTextDocumentRequest> didOpenTextDocumentNotification =
        MessageFactory::createDidOpenTextDocumentReq(jsonRPC);

    // TODO Update internal document state
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with notification: textDocument/didChange");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<DidChangeTextDocumentRequest> didChangeTextDocumentReq =
        MessageFactory::createDidChangeTextDocumentReq(jsonRPC);

    // TODO Update internal document state
}

void JustAnLSPFacade::handleTextDocumentCompletionRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with notification: textDocument/completion");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_COMPLETION);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    // TODO create request and move logic from here
    std::vector<CompletionItem> completionItems{
        {"dnsClient", "DNS client test 1", "DNS client test 1 documentation"},
        {"dnsClientId", "DNS client test 1", "DNS client id test 1 documentation"},
        {"dnsClientIpAddress", "DNS client ip address test 1", "DNS client ip address test 1 documentation"},
    };

    int64_t id = jsonRPC["id"].get<int64_t>();

    CompletionResponse completionResponse{"2.0", id, {completionItems}};

    Rpc::send(completionResponse);
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with method: textDocument/hover");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    // TODO basic response
}

void JustAnLSPFacade::ensureNoReqIsProcessedAfterShutdown(const nlohmann::json &jsonRPC)
{
    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        LOG_ERROR("Received request after shutdown");
        m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }
}

} // namespace justanlsp
