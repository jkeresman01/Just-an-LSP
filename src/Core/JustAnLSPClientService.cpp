#include "JUstAnLSPClientService.h"

#include "../Utils/Logger.h"

namespace justanlsp
{

uint32_t JustAnLSPClientService::m_clientId = 0;

void JustAnLSPClientService::registerClient(const JustAnLSPClient &client)
{
    m_registeredClients.emplace(++m_clientId, client);

    JLSP_INFO(STR("Client with ID: %u, ( %s ) has been successfully registered!", m_clientId,
                  client.getInfo().c_str()));
}

JustAnLSPClient JustAnLSPClientService::getClientById(uint32_t clientId) const
{
    auto it = m_registeredClients.find(clientId);

    if (it == m_registeredClients.end())
    {
        JLSP_ERROR(STR("There are no registered clients with ID: %u!", clientId));
    }

    return it->second;
}

JustAnLSPClientService &JustAnLSPClientService::getInstance()
{
    static JustAnLSPClientService instance;
    return instance;
}

} // namespace justanlsp
