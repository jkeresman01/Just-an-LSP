#include "JustAnLSPReqHandler.h"

#include "../enums/TextDocumentSyncKind.h"
#include "../messages/InitializeResponse.h"
#include "../rpc/Rpc.h"
#include "../utils/Logger.h"
#include "JUstAnLSPClientService.h"

namespace justanlsp
{
void JustAnLSPReqHandler::initializeRequest(const std::shared_ptr<InitializeRequest> &initializeRequest)
{
    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    bool isInitializeReqFirstReceived =
        m_justAnLspCounters->getValue(RequestType::INITIALIZE) == 1 and m_justAnLspCounters->getSum() == 1;

    if (!isInitializeReqFirstReceived)
    {
        LOG_ERROR << "Initialize request should be the first that is send from client to JustAnLSP server!";
    }

    InitializeParams initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> clientCapabilities = initializeParams.getClientCapabilites();
    ClientInfo clientInfo = initializeParams.getClientInfo();

    JustAnLSPClientService::getInstance().registerClient({clientInfo, clientCapabilities});

    InitializeResponse initializeResponse({"JustAnLSP", "0.0.0.0.0.1-alpha"}, {TextDocumentSyncKind::FULL});

    Rpc::send(initializeResponse);
}

void JustAnLSPReqHandler::shutdownRequest(const std::shared_ptr<ShutdownRequest> &shutdownRequest) {}

} // namespace justanlsp
