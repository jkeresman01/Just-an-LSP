#include "JustAnLSPReqHandler.h"

#include <cstdint>

#include "../enums/TextDocumentSyncKind.h"
#include "../messages/response/CompletionResponse.h"
#include "../messages/response/InitializeResponse.h"
#include "../messages/response/ShutdownResponse.h"
#include "../params/DidChangeTextDocumentParams.h"
#include "../params/DidOpenTextDocumentParams.h"
#include "../rpc/Rpc.h"
#include "../types/CompletionItem.h"
#include "../types/TextDocumentItem.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

void JustAnLSPReqHandler::initializeReq(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    LOG_INFO("Processing textDocument/initialize request");

    std::shared_ptr<InitializeParams> initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams->getClientCapabilites();
    ClientInfo clientInfo = initializeParams->getClientInfo();

    LOG_INFO(STR("Client: %s has sent initializtion request", clientInfo.toString().c_str()));

    m_justAnLSPClient->saveInfo(clientInfo);
    m_justAnLSPClient->registerCapabilites(clientCapabilities);

    InitializeResult initializeResult({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});
    InitializeResponse initializeResponse("2.0", initializeRequest->getId(), initializeResult);

    Rpc::send(initializeResponse);

    LOG_INFO(STR("Initialize response was successfully sent for client: %s", clientInfo.toString().c_str()));
}

void JustAnLSPReqHandler::textDocumentDidOpenReq(
    const std::shared_ptr<DidOpenTextDocumentRequest> &didOpenTextDocumentReq)
{
    std::shared_ptr<DidOpenTextDocumentParams> didOpenParams = didOpenTextDocumentReq->getParams();
    std::shared_ptr<TextDocumentItem> textDocumentItem = didOpenParams->getTextDocumentItem();

    m_justAnLSPClient->addDocument(textDocumentItem->getURI(), textDocumentItem->getText());

    LOG_INFO("Request with method: textDocument/didOpen was successfully processed");
}

void JustAnLSPReqHandler::textDocumentCompletionReq(const std::shared_ptr<CompletionRequest> &completionReq)
{
    // TODO Move this out, it's just to test communcation
    std::vector<CompletionItem> completionItems{
        {"dnsClient", "DNS client test 1", "DNS client test 1 documentation"},
        {"dnsClientId", "DNS client test 1", "DNS client id test 1 documentation"},
        {"dnsClientIpAddress", "DNS client ip address test 1", "DNS client ip address test 1 documentation"},
    };

    int64_t requestId = completionReq->getId();

    CompletionResponse completionResponse{"2.0", requestId, {completionItems}};

    Rpc::send(completionResponse);
}

void JustAnLSPReqHandler::textDocumentDidChangeReq(
    const std::shared_ptr<DidChangeTextDocumentRequest> &didChangeTextDocumentReq)
{
    LOG_INFO("Processing textDocument/didChange request");

    std::shared_ptr<DidChangeTextDocumentParams> didChangeParams = didChangeTextDocumentReq->getParams();

    std::string URI = didChangeParams->getChangedDocumentURI();
    std::string contentChanges = didChangeParams->getContentChanges();

    m_justAnLSPClient->updateDocumentByURI(URI, contentChanges);
}

void JustAnLSPReqHandler::shutdownReq(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    LOG_INFO("Processing shutdown request");

    ShutdownResponse shutdownResponse{"2.0", shutdownRequest->getId()};

    Rpc::send(shutdownResponse);

    LOG_INFO("Response was sent for shutdown request!");
}

} // namespace justanlsp
