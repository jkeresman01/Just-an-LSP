#include "JustAnLSPFacade.h"

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

namespace justanlsp
{

void JustAnLSPFacade::handleRequest(const nlohmann::json &request)
{
    LOG_INFO << "Entered handleRequest in Facade impl";

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
        LOG_WARN << "Received request of unkown type";
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received initialize request";

    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    bool isInitializeReqReceivedFirst = m_justAnLspCounters->getSum() == 1;
    if (!isInitializeReqReceivedFirst)
    {
        LOG_ERROR << "Received reqeuest before initialization";
        m_justAnLSPErrorHandler->handleServerNotInitalizedError();
    }

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(jsonRPC);
    LOG_INFO << "Successfully constructed initializeRequest";

    m_justAnLSPReqHandler->initializeRequest(initializeRequest);
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received shutdown request";

    /* std::shared_ptr<ShutdownRequest> shutdownRequest = MessageFactory::createShutdownReq(jsonRPC); */
    /* m_justAnLSPReqHandler->shutdownRequest(shutdownRequest); */
}

void JustAnLSPFacade::handleInitializedRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received initialized request";

    // TODO basic response
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received textDocument/hover request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);
}

void JustAnLSPFacade::handleTextDocumentDidOpenRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received textDocument/didOpen request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    // TODO basic response
}

void JustAnLSPFacade::handleTextDocumentDidChangeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received textDocument/didChange request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    // TODO basic response
}

} // namespace justanlsp
