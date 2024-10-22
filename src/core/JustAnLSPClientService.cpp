#include "JUstAnLSPClientService.h"

#include "../utils/Logger.h"

namespace justanlsp
{

uint32_t JustAnLSPClientService::m_clientId = 0;

void JustAnLSPClientService::registerClient(const JustAnLSPClient &client)
{
    m_registeredClients.emplace(++m_clientId, client);

    LOG_INFO << "Client with ID: " << m_clientId << " (" << client.getInfo()
             << ") has been successfully registered"
             << "!";
}

JustAnLSPClient JustAnLSPClientService::getClientById(uint32_t clientId) const
{
    JustAnLSPClientsMapT::iterator it = m_registeredClients.find(clientId);

    if (it == m_registeredClients.end())
    {
        LOG_ERROR << "There are no registered clients with ID: << clientId" << "!";
    }

    return it->second;
}

JustAnLSPClientService &JustAnLSPClientService::getInstance()
{
    static JustAnLSPClientService instance;
    return instance;
}

} // namespace justanlsp
