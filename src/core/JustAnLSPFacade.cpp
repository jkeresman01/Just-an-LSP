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
        LOG_WARN << "Received request of unkown type";
        break;
    }
}

void JustAnLSPFacade::handleInitializeRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received initialize request";

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(jsonRPC);

    m_justAnLSPReqHandler->initializeRequest(initializeRequest);
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received shutdown request";

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    nlohmann::json response = {{"jsonrpc", "2.0"}, {"id", jsonRPC["id"]}, {"result", nullptr}};

    LOG_INFO << "Sending shutdown response: " << response.dump(4);

    std::string responseBody = response.dump();
    std::cout << "Content-Length: " << responseBody.size() << "\r\n\r\n";
    std::cout << responseBody << std::endl;
}

void JustAnLSPFacade::handleInitializedRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received initialized request";
    LOG_INFO << "Successfull connectio between client and JustAnLSPServer";
}

void JustAnLSPFacade::handleTextDocumentHoverRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received textDocument/hover request";

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    // TODO basic response
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
