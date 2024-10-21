#pragma once

#include "../capabilities/ClientCapabilites.h"
#include "../types/ClientInfo.h"

#include <memory>

namespace justanlsp
{
class JustAnLSPClient
{
  public:
    JustAnLSPClient() = default;

    void registerCapabilites(const std::shared_ptr<ClientCapabilities> &clientCapabilites)
    {
        m_clientCapabilities = clientCapabilites;
    };

    void saveInfo(const ClientInfo &clientInfo) { m_clientInfo = clientInfo; };

  private:
    std::shared_ptr<ClientCapabilities> m_clientCapabilities = std::make_shared<ClientCapabilities>();
    ClientInfo m_clientInfo;
};
} // namespace justanlsp
