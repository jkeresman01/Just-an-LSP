#pragma once

#include "ClientCapabilites.h"
#include "ClientInfo.h"

#include <memory>

namespace justanlsp
{
class Client
{
  public:
    Client() = default;

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
