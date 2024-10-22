#include "JUstAnLSPClientService.h"

#include "../utils/Logger.h"

namespace justanlsp
{

uint32_t JustAnLSPClientService::m_clientId = 0;

void JustAnLSPClientService::registerClient(const JustAnLSPClient &client)
{
    m_registeredClients.emplace(++m_clientId, client);
}

JustAnLSPClient JustAnLSPClientService::getClientById(uint32_t clientId) const
{
    JustAnLSPClientsMapT::iterator it = m_registeredClients.find(clientId);

    if (it == m_registeredClients.end())
    {
        LOG_ERROR << "Client with id: " << m_clientId << " doesn't exist!";
    }

    return it->second;
}

JustAnLSPClientService &JustAnLSPClientService::getInstance()
{
    static JustAnLSPClientService instance;
    return instance;
}

} // namespace justanlsp
