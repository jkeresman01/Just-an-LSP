#pragma once

#include "ClientCapabilites.h"

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

  private:
    std::shared_ptr<ClientCapabilities> m_clientCapabilities = std::make_shared<ClientCapabilities>();
};
} // namespace justanlsp
