#include "JustAnLSPReqHandler.h"

#include <cstdint>

#include "../enums/TextDocumentSyncKind.h"
#include "../messages/InitializeResponse.h"
#include "../messages/ShutdownResponse.h"
#include "../rpc/Rpc.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

void JustAnLSPReqHandler::initializeReq(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    std::shared_ptr<InitializeParams> initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams->getClientCapabilites();
    ClientInfo clientInfo = initializeParams->getClientInfo();

    LOG_INFO(STR("%s has sent initializtion request", clientInfo.toString().c_str()));

    JustAnLSPClientService::getInstance().registerClient({clientInfo, clientCapabilities});

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

    LOG_INFO("textDocument/didOpen request was successfully processed");
}

void JustAnLSPReqHandler::shutdownReq(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    LOG_INFO("Processing shutdown request");

    ShutdownResponse shutdownResponse{"2.0", shutdownRequest->getId()};

    Rpc::send(shutdownResponse);

    LOG_INFO("Response was sent for shutdown hequest!");
}

} // namespace justanlsp
