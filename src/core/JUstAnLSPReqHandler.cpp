#include "JustAnLSPReqHandler.h"

#include "../enums/TextDocumentSyncKind.h"
#include "../messages/InitializeResponse.h"
#include "../rpc/Rpc.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{

void JustAnLSPReqHandler::initializeRequest(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    std::shared_ptr<InitializeParams> initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams->getClientCapabilites();
    ClientInfo clientInfo = initializeParams->getClientInfo();

    LOG_INFO << "Client: " << clientInfo.toString() << " has sent initializtion request";

    JustAnLSPClientService::getInstance().registerClient({clientInfo, clientCapabilities});

    InitializeResult initializeResult({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});
    InitializeResponse initializeResponse("2.0", 1, initializeResult);

    std::string responseBody = initializeResponse.toJson().dump();
    std::cout << "Content-Length: " << responseBody.size() << "\r\n\r\n";
    std::cout << responseBody << std::endl;

    LOG_INFO << "Initialize response was successfully sent for client: " << clientInfo.toString();
}

void JustAnLSPReqHandler::shutdownRequest(const std::shared_ptr<ShutdownRequest> &shutdownRequest)
{
    LOG_INFO << "Processing shutdown request";

    /* ResponseMessage successfullShutdownResponse = ResponseMessage::Builder().withResult("null").build(); */

    /* Rpc::send(successfullShutdownResponse); */

    LOG_INFO << "Response was sent for shutdown requestq!";
}

} // namespace justanlsp
