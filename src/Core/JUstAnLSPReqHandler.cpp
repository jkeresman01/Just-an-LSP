#include "JustAnLSPReqHandler.h"
#include <vector>

#include "../Capabilities/ServerCapabilities.h"
#include "../Capabilities/ServerCapabilitiesDirector.h"
#include "../CodeActions/CodeActionProviderFactory.h"
#include "../Completions/CompletionProviderFactory.h"
#include "../Completions/FakeCompletionProvider.h"
#include "../Completions/ICompletionProvider.h"
#include "../Diagnostics/DiagnosticsProviderFactory.h"
#include "../Diagnostics/FakeDiagnosticsProvider.h"
#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Enums/TextDocumentSyncKind.h"
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

JustAnLSPReqHandler::JustAnLSPReqHandler()
{
    m_diagnosticsProvider = DiagnosticsProviderFactory::create();
    m_completionProvider = CompletionProviderFactory::create();
    m_codeActionsProvider = CodeActionsProviderFactory::create();
}

void JustAnLSPReqHandler::initializeReq(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    JLSP_DEBUG("Processing textDocument/initialize request");

    std::shared_ptr<InitializeParams> initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> capabilities = initializeParams->getClientCapabilites();
    ClientInfo info = initializeParams->getClientInfo();

    JLSP_DEBUG(STR("Client: %s has sent initializtion request", info.toString().c_str()));

    m_justAnLSPClient->saveInfo(info);
    m_justAnLSPClient->registerCapabilites(capabilities);

    ServerCapabilities::Builder builder;
    ServerCapabilities serverCapabilites = ServerCapabilitiesDirector::getDefaultServerCapabilites(builder);

    InitializeResult initializeResult({"JustAnLSP", "0.0.0.0.0.1-alpha"}, serverCapabilites);
    InitializeResponse initializeResponse("2.0", initializeRequest->getId(), initializeResult);

    Rpc::send(initializeResponse);

    JLSP_DEBUG(STR("Initialize response was successfully sent for client: %s", info.toString().c_str()));
}

void JustAnLSPReqHandler::textDocumentDidOpenReq(
    const std::shared_ptr<DidOpenTextDocumentRequest> &didOpenTextDocumentReq)
{
    JLSP_DEBUG("Processing textDocument/didOpen request");

    std::shared_ptr<DidOpenTextDocumentParams> didOpenParams = didOpenTextDocumentReq->getParams();
    std::shared_ptr<TextDocumentItem> textDocumentItem = didOpenParams->getTextDocumentItem();

    std::string URI = textDocumentItem->getURI();
    std::string textDocumentContent = textDocumentItem->getText();

    m_justAnLSPClient->addDocument(URI, textDocumentContent);

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    std::vector<Diagnostic> diagnostics = m_diagnosticsProvider->getDiagnostics(document, Position{10, 10});

    std::shared_ptr<PublishDiagnosticsParams> diagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNoticifation publishDiagnostics("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(publishDiagnostics);

    JLSP_DEBUG("Request with method: textDocument/didOpen was successfully processed");
}

void JustAnLSPReqHandler::textDocumentDidChangeReq(
    const std::shared_ptr<DidChangeTextDocumentRequest> &didChangeTextDocumentReq)
{
    JLSP_DEBUG("Processing textDocument/didChange request");

    std::shared_ptr<DidChangeTextDocumentParams> didChangeParams = didChangeTextDocumentReq->getParams();

    std::string URI = didChangeParams->getChangedDocumentURI();
    std::string contentChanges = didChangeParams->getContentChanges();

    m_justAnLSPClient->updateDocumentWithURI(URI, contentChanges);

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    std::vector<Diagnostic> diagnostics = m_diagnosticsProvider->getDiagnostics(document, Position{10, 10});

    std::shared_ptr<PublishDiagnosticsParams> diagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNoticifation publishDiagnostics("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(publishDiagnostics);

    JLSP_DEBUG("Response successfully sent for textDocument/didChangerequest");
}

void JustAnLSPReqHandler::textDocumentCompletionReq(const std::shared_ptr<CompletionRequest> &completionReq)
{
    JLSP_DEBUG("Processing textDocument/completion request");

    std::vector<CompletionItem> completionItems = m_completionProvider->getCompletions();

    int64_t requestId = completionReq->getId();

    CompletionResult completionResult(completionItems);
    CompletionResponse completionResponse{"2.0", requestId, completionResult};

    Rpc::send(completionResponse);

    JLSP_DEBUG("Response successfully sent for textDocument/completion request");
}

void JustAnLSPReqHandler::textDocumentHoverReq(const std::shared_ptr<HoverRequest> &hoverTextDocumentReq)
{
    JLSP_DEBUG("Processing textDocument/hover request");

    std::shared_ptr<HoverParams> hoverParams = hoverTextDocumentReq->getParams();

    std::string URI = hoverParams->getTextDocumentIdentifier().URI;
    Position position = hoverParams->getPosition();

    std::string document = m_justAnLSPClient->getDocumentByURI(URI);

    // TODO hover logic
}

void JustAnLSPReqHandler::textDocumentCodeActionReq(
    const std::shared_ptr<CodeActionRequest> &codeActionRequest)
{
    JLSP_DEBUG("Processing textDocument/codeAction request");

    std::shared_ptr<CodeActionParams> codeActionParams = codeActionRequest->getParams();

    // TODO hover logic
}

void JustAnLSPReqHandler::shutdownReq(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    JLSP_DEBUG("Processing shutdown request");

    ShutdownResponse shutdownResponse{"2.0", shutdownRequest->getId()};

    Rpc::send(shutdownResponse);

    JLSP_DEBUG("Response was sent for shutdown request!");
}

} // namespace justanlsp
