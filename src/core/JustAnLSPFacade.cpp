#include "JustAnLSPFacade.h"
#include "JustAnLSPServer.h"

#include <iostream>
#include <memory>

#include "../enums/RequestType.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../factories/MessageFactory.h"
#include "../messages/InitializeResponse.h"
#include "../messages/ResponseMessage.h"
#include "../messages/ShutdownRequest.h"
#include "../params/InitializeParams.h"
#include "../rpc/Rpc.h"
#include "../types/ClientInfo.h"
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
    case RequestType::TEXT_DOCUMENT_HOVER:
        handleTextDocumentHoverRequest(request);
        break;
    default:
        LOG_ERROR << "Received request/notification with method: UNKNOWN_TYPE";
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Prcoessing request with method: initialize";

    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    bool isInitializeReqReceivedFirst = m_justAnLspCounters->getSum() <= 1;
    if (!isInitializeReqReceivedFirst)
    {
        LOG_ERROR << "Received request before initialization";
        m_justAnLSPErrorHandler->handleServerNotInitalizedError(jsonRPC["id"]);
    }

    bool wasShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN);
    if(wasShutdownReqReceived)
    {
       LOG_ERROR << "Received request after shutdown"; 
       m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(jsonRPC);

    m_justAnLSPReqHandler->initializeRequest(initializeRequest);
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received request with method: shutdown";

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    std::shared_ptr<ShutdownRequest> shutdownRequest = MessageFactory::createShutdownReq(jsonRPC);

    m_justAnLSPReqHandler->shutdownRequest(shutdownRequest);
}

void JustAnLSPFacade::handleInitializedRequest(const nlohmann::json &jsonRPC)
{
    m_justAnLspCounters->increment(RequestType::INITIALIZED);

    bool wasShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN);
    if(wasShutdownReqReceived)
    {
       LOG_ERROR << "Received request after shutdown"; 
       m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }

    LOG_INFO << "Received notification with method: initialized";
    LOG_INFO << "Successful connection between client and JustAnLSPServer has been established";
}

void JustAnLSPFacade::handleTextDocumentDidOpenRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received notification with method: textDocument/didOpen";

    bool wasShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN);
    if(wasShutdownReqReceived)
    {
       LOG_ERROR << "Received request after shutdown"; 
       m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }

    std::shared_ptr<DidOpenTextDocumentRequest> didOpenTextDocumentNotification =
        MessageFactory::createDidOpenTextDocumentReq(jsonRPC);

    // TODO Update internal document state
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received request with notification: textDocument/didChange";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    bool wasShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN);
    if(wasShutdownReqReceived)
    {
       LOG_ERROR << "Received request after shutdown"; 
       m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }

    // TODO Update internal document state
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received request with method: textDocument/hover";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    bool wasShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN);
    if(wasShutdownReqReceived)
    {
       LOG_ERROR << "Received request after shutdown"; 
       m_justAnLSPErrorHandler->handleReceivedReqAfterShutdownError(jsonRPC["id"]);
    }

    // TODO basic response
}

} // namespace justanlsp
