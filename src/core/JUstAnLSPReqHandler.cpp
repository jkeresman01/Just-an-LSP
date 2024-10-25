#include "JustAnLSPReqHandler.h"

#include "../enums/TextDocumentSyncKind.h"
#include "../messages/InitializeResponse.h"
#include "../rpc/Rpc.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

void JustAnLSPReqHandler::initializeRequest(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    LOG_INFO << "Processing initialize request";

    std::shared_ptr<InitializeParams> initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams->getClientCapabilites();
    ClientInfo clientInfo = initializeParams->getClientInfo();

    LOG_INFO << "Client: " << clientInfo.toString() << " has sent initializtion request";

    JustAnLSPClientService::getInstance().registerClient({clientInfo, clientCapabilities});

    LOG_INFO << "Client: " << clientInfo.toString() << " was successfully registered";

    InitializeResponse initializeResponse({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});

    LOG_INFO << "Sending " << initializeResponse.toString();

    Rpc::send(initializeResponse);

    LOG_INFO << "Initialize response was successfully sent for client: " << clientInfo.toString();
}

void JustAnLSPReqHandler::shutdownRequest(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    LOG_INFO << "Processing shutdown request";

    ResponseMessage successfullShutdownResponse = ResponseMessage::Builder().withResult("null").build();

    Rpc::send(successfullShutdownResponse);

    LOG_INFO << "Response was sent for shutdown requestq!";
}

} // namespace justanlsp
