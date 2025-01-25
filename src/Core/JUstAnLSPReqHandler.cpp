#include "JustAnLSPReqHandler.h"
#include <vector>

#include "../Capabilities/ServerCapabilities.h"
#include "../Capabilities/ServerCapabilitiesDirector.h"
#include "../Completions/FakeCompletionProvider.h"
#include "../Completions/ICompletionProvider.h"
#include "../Diagnostics/FakeDiagnosticsProvider.h"
#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Enums/TextDocumentSyncKind.h"
#include "../Factories/CompletionProviderFactory.h"
#include "../Factories/DiagnosticsProviderFactory.h"
#include "../Messages/Notification/PublishDiagnosticsNotification.h"
#include "../Messages/Response/CompletionResponse.h"
#include "../Messages/Response/InitializeResponse.h"
#include "../Messages/Response/ShutdownResponse.h"
#include "../Params/DidChangeTextDocumentParams.h"
#include "../Params/DidOpenTextDocumentParams.h"
#include "../Params/PublishDiagnosticsParams.h"
#include "../Results/CompletionResult.h"
#include "../Rpc/Rpc.h"
#include "../Types/CompletionItem.h"
#include "../Types/Diagnostic.h"
#include "../Types/TextDocumentItem.h"
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

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    //TODO instanitatediagnostics provider on creation of reqHandler
    std::shared_ptr<IDiagnosticsProvider> diagnosticsProvider = DiagnosticsProviderFactory::create();

    //TODO remove position from diagonostics provider
    std::vector<Diagnostic> diagnostics = diagnosticsProvider->getDiagnostics(document, Position{10,10});

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

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    //TODO instanitatediagnostics provider on creation of reqHandler
    std::shared_ptr<IDiagnosticsProvider> diagnosticsProvider = DiagnosticsProviderFactory::create();

    //TODO remove position from diagonostics provider
    std::vector<Diagnostic> diagnostics = diagnosticsProvider->getDiagnostics(document, Position{10, 10});

    std::shared_ptr<PublishDiagnosticsParams> diagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNoticifation publishDiagnostics("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(publishDiagnostics);
}

void JustAnLSPReqHandler::textDocumentCompletionReq(const std::shared_ptr<CompletionRequest> &completionReq)
{
    std::shared_ptr<ICompletionProvider> completionsProvider = CompletionProviderFactory::create();
    std::vector<CompletionItem> completionItems = completionsProvider->getCompletions();

    int64_t requestId = completionReq->getId();

    CompletionResult completionResult(completionItems);
    CompletionResponse completionResponse{"2.0", requestId, completionResult};

    Rpc::send(completionResponse);
}

void JustAnLSPReqHandler::textDocumentHoverReq(const std::shared_ptr<HoverRequest> &hoverTextDocumentReq)
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
