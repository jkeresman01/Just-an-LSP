#include "JustAnLSPFacade.h"
#include "JustAnLSPServer.h"

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include "../enums/RequestType.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../factories/MessageFactory.h"
#include "../messages/request/DidChangeTextDocumentRequest.h"
#include "../messages/request/ShutdownRequest.h"
#include "../messages/request/HoverRequest.h"
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
    case RequestType::SHUTDOWN:
        handleShutdownRequest(request);
        break;
    case RequestType::EXIT:
        handleExitRequest(request);
        break;
    default:
        LOG_ERROR("Received request/notification with method: UNKNOWN_TYPE");
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with method: initialize");

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

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<DidOpenTextDocumentRequest> didOpenTextDocumentNotification =
        MessageFactory::createDidOpenTextDocumentReq(jsonRPC);

    m_justAnLSPReqHandler->textDocumentDidOpenReq(didOpenTextDocumentNotification);
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with notification: textDocument/didChange");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<DidChangeTextDocumentRequest> didChangeTextDocumentReq =
        MessageFactory::createDidChangeTextDocumentReq(jsonRPC);

    m_justAnLSPReqHandler->textDocumentDidChangeReq(didChangeTextDocumentReq);
}

void JustAnLSPFacade::handleTextDocumentCompletionRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with notification: textDocument/completion");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_COMPLETION);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<CompletionRequest> completionRequest = MessageFactory::createCompletionReq(jsonRPC);

    m_justAnLSPReqHandler->textDocumentCompletionReq(completionRequest);
}

void JustAnLSPFacade::handleExitRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received notification with method: exit");

    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        LOG_INFO("Exiting with status code 0 (successful shutdown)");
        std::exit(0);
    }
    else
    {
        LOG_ERROR("Exiting with status code 1 (shutdown not received)");
        std::exit(1);
    }
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO("Received request with method: textDocument/hover");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    ensureNoReqIsProcessedAfterShutdown(jsonRPC);

    std::shared_ptr<HoverRequest> hoverRequest = MessageFactory::createHoverReq(jsonRPC);
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
