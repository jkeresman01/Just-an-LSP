#include "JustAnLSPFacade.h"

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
    LOG_INFO << jsonRPC.dump(4);

    // Create InitializeResult with your server capabilities
    InitializeResult initializeResult({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});
    InitializeResponse initializeResponse("2.0", jsonRPC["id"], initializeResult);

    LOG_INFO << "Sending initialize response: ";
    LOG_INFO << initializeResponse.toJson().dump(4);

    // Calculate the correct Content-Length for the response
    std::string responseBody = initializeResponse.toJson().dump();
    std::cout << "Content-Length: " << responseBody.size() << "\r\n\r\n";
    std::cout << responseBody << std::endl;
}

void JustAnLSPFacade::handleShutdownRequest(const nlohmann::json &jsonRPC)
{
    LOG_INFO << "Received shutdown request";

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    // TODO basic response
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
