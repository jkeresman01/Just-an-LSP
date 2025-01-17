#include "JustAnLSPReqHandler.h"

#include <cstdint>
#include <vector>

#include "../capabilities/ServerCapabilities.h"
#include "../capabilities/ServerCapabilitiesDirector.h"
#include "../enums/TextDocumentSyncKind.h"
#include "../messages/notification/PublishDiagnosticsNotification.h"
#include "../messages/response/CompletionResponse.h"
#include "../messages/response/InitializeResponse.h"
#include "../messages/response/ShutdownResponse.h"
#include "../params/DidChangeTextDocumentParams.h"
#include "../params/DidOpenTextDocumentParams.h"
#include "../params/PublishDiagnosticsParams.h"
#include "../results/CompletionResult.h"
#include "../rpc/Rpc.h"
#include "../types/CompletionItem.h"
#include "../types/Diagnostic.h"
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

    ServerCapabilities::Builder builder;
    ServerCapabilities serverCapabilites = ServerCapabilitiesDirector::getDefaultServerCapabilites(builder);

    InitializeResult initializeResult({"JustAnLSP", "0.0.0.0.0.1-alpha"}, serverCapabilites);
    InitializeResponse initializeResponse("2.0", initializeRequest->getId(), initializeResult);

    Rpc::send(initializeResponse);

    LOG_INFO(STR("Initialize response was successfully sent for client: %s", clientInfo.toString().c_str()));
}

void JustAnLSPReqHandler::textDocumentDidOpenReq(
    const std::shared_ptr<DidOpenTextDocumentRequest> &didOpenTextDocumentReq)
{
    std::shared_ptr<DidOpenTextDocumentParams> didOpenParams = didOpenTextDocumentReq->getParams();
    std::shared_ptr<TextDocumentItem> textDocumentItem = didOpenParams->getTextDocumentItem();

    std::string URI = textDocumentItem->getURI();
    std::string textDocumentContent = textDocumentItem->getText();

    m_justAnLSPClient->addDocument(URI, textDocumentContent);

    std::vector<Diagnostic> diagnostics{
        {{10, 10}, DiagnosticSeverity::ERROR, "Source is this stuff", "THis is really big error msg!!!"}};

    // TODO Move this out, it's here just to test communication
    std::shared_ptr<PublishDiagnosticsParams> diagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNoticifation publishDiagnostics("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(publishDiagnostics);

    LOG_INFO("Request with method: textDocument/didOpen was successfully processed");
}

void JustAnLSPReqHandler::textDocumentDidChangeReq(
    const std::shared_ptr<DidChangeTextDocumentRequest> &didChangeTextDocumentReq)
{
    LOG_INFO("Processing textDocument/didChange request");

    std::shared_ptr<DidChangeTextDocumentParams> didChangeParams = didChangeTextDocumentReq->getParams();

    std::string URI = didChangeParams->getChangedDocumentURI();
    std::string contentChanges = didChangeParams->getContentChanges();

    m_justAnLSPClient->updateDocumentWithURI(URI, contentChanges);

    // TODO Move this out, it's here just to test communication
    std::vector<Diagnostic> diagnostics{
        {{10, 10}, DiagnosticSeverity::ERROR, "Source is this stuff", "THis is really big error msg!!!"}};

    std::shared_ptr<PublishDiagnosticsParams> diagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNoticifation publishDiagnostics("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(publishDiagnostics);
}

void JustAnLSPReqHandler::textDocumentCompletionReq(const std::shared_ptr<CompletionRequest> &completionReq)
{
    // TODO Move this out, it's here just to test communication
    std::vector<CompletionItem> completionItems{
        {"dnsClient", "DNS client test 1", "DNS client test 1 documentation", "dnsClient"},
        {"dnsClientId", "DNS client test 1", "DNS client id test 1 documentation", "dnsClientId"},
        {"dnsClientIpAddress", "DNS client ip address test 1", "DNS client ip address test 1 documentation",
         "dnsClientIpAddress"},
    };

    int64_t requestId = completionReq->getId();

    CompletionResult completionResult(completionItems);
    CompletionResponse completionResponse{"2.0", requestId, completionResult};

    Rpc::send(completionResponse);
}

void JustAnLSPReqHandler::textDocumenHoverReq(const std::shared_ptr<HoverRequest> &hoverTextDocumentReq)
{
    std::shared_ptr<HoverParams> hoverParams = hoverTextDocumentReq->getParams();

    std::string URI = hoverParams->getTextDocumentIdentifier().URI;
    Position position = hoverParams->getPosition();

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    (void)position;
    (void)document;

    // TODO hover logic
}

void JustAnLSPReqHandler::shutdownReq(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    LOG_INFO("Processing shutdown request");

    ShutdownResponse shutdownResponse{"2.0", shutdownRequest->getId()};

    Rpc::send(shutdownResponse);

    LOG_INFO("Response was sent for shutdown request!");
}

} // namespace justanlsp
