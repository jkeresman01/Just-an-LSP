#include "JustAnLSPClient.h"

#include <memory>

namespace justanlsp
{
JustAnLSPClient::JustAnLSPClient(const ClientInfo &clientInfo,
                                 const std::shared_ptr<ClientCapabilities> &clientCapabilites)
{
    saveInfo(clientInfo);
    registerCapabilites(clientCapabilites);
}

void JustAnLSPClient::saveInfo(const ClientInfo &clientInfo)
{
    m_clientInfo = clientInfo;
}

void JustAnLSPClient::registerCapabilites(const std::shared_ptr<ClientCapabilities> &clientCapabilites)
{
    m_clientCapabilities = clientCapabilites;
}
} // namespace justanlsp
