#include "JustAnLSPFacade.h"
#include "JustAnLSPServer.h"

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include "../Enums/ExitStatus.h"
#include "../Enums/RequestType.h"
#include "../Enums/TextDocumentSyncKind.h"
#include "../Messages/FactoryIml/MessageFactory.h"
#include "../Messages/Request/CodeActionRequest.h"
#include "../Messages/Request/DidChangeTextDocumentRequest.h"
#include "../Messages/Request/HoverRequest.h"
#include "../Messages/Request/ShutdownRequest.h"
#include "../Messages/Response/CompletionResponse.h"
#include "../Messages/Response/ResponseMessage.h"
#include "../Params/InitializeParams.h"
#include "../Rpc/Rpc.h"
#include "../Types/ClientInfo.h"
#include "../Types/CompletionItem.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"
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
    case RequestType::TEXT_DOCUMENT_CODE_ACTION:
        handleTextDocumentCodeActionRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DEFINITION:
        handleTextDocumentDefintionRequest(request);
        break;
    case RequestType::SHUTDOWN:
        handleShutdownRequest(request);
        break;
    case RequestType::EXIT:
        handleExitRequest(request);
        break;
    default:
        JLSP_ERROR("Received request/notification with method: UNKNOWN_TYPE");
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: initialize");

    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(request);

    m_justAnLSPReqHandler->initializeReq(initializeRequest);
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: shutdown");

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    std::shared_ptr<ShutdownRequest> shutdownRequest = MessageFactory::createShutdownReq(request);

    m_justAnLSPReqHandler->shutdownReq(shutdownRequest);
}

void JustAnLSPFacade::handleInitializedRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received notification with method: initialized");

    m_justAnLspCounters->increment(RequestType::INITIALIZED);

    ensureNoReqIsProcessedAfterShutdown(request);

    JLSP_DEBUG("Successful connection between client and JustAnLSPServer has been established");
}

void JustAnLSPFacade::handleTextDocumentDidOpenRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received notification with method: textDocument/didOpen");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DidOpenTextDocumentRequest> didOpenTextDocumentNotification =
        MessageFactory::createDidOpenTextDocumentReq(request);

    m_justAnLSPReqHandler->textDocumentDidOpenReq(didOpenTextDocumentNotification);
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: textDocument/didChange");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DidChangeTextDocumentRequest> didChangeTextDocumentReq =
        MessageFactory::createDidChangeTextDocumentReq(request);

    m_justAnLSPReqHandler->textDocumentDidChangeReq(didChangeTextDocumentReq);
}

void JustAnLSPFacade::handleTextDocumentCompletionRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: textDocument/completion");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_COMPLETION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<CompletionRequest> completionRequest = MessageFactory::createCompletionReq(request);

    m_justAnLSPReqHandler->textDocumentCompletionReq(completionRequest);
}

void JustAnLSPFacade::handleExitRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received notification with method: exit");

    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        JLSP_DEBUG("Exiting with status code 0 (successful shutdown)");
        std::exit(ExitStatus::SUCCESS);
    }
    else
    {
        JLSP_ERROR("Exiting with status code 1 (shutdown not received)");
        std::exit(ExitStatus::FAILURE);
    }
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: textDocument/hover");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<HoverRequest> hoverRequest = MessageFactory::createHoverReq(request);

    m_justAnLSPReqHandler->textDocumentHoverReq(hoverRequest);
}

void JustAnLSPFacade::handleTextDocumentCodeActionRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: textDocument/codeAction");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_CODE_ACTION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<CodeActionRequest> codeActionRequest = MessageFactory::createCodeActionRequest(request);

    m_justAnLSPReqHandler->textDocumentCodeActionReq(codeActionRequest);
}

void JustAnLSPFacade::handleTextDocumentDefintionRequest(const nlohmann::json &request)
{
    JLSP_DEBUG("Received request with method: textDocument/codeAction");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DEFINITION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DefintionRequest> definitionRequest =
        MessageFactory::createGoToDefinitionRequest(request);

    m_justAnLSPReqHandler->textDocumentDefinitionReq(definitionRequest);
}

void JustAnLSPFacade::ensureNoReqIsProcessedAfterShutdown(const nlohmann::json &request)
{
    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        JLSP_ERROR("Received request after shutdown");
        m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(request["id"]);
    }
}

} // namespace justanlsp
