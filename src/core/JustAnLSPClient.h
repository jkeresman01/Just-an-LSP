#pragma once

#include "../capabilities/ClientCapabilites.h"
#include "../types/ClientInfo.h"

#include <memory>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPClient
///
/// @brief Represent the client that connects to JustAnLSP server
///
//////////////////////////////////////////////////////////////
class JustAnLSPClient
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPClient() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Registers client capabilities (features supported
    ///        by the editor or tool)
    ///
    /// @param clientCapabilites
    ///
    //////////////////////////////////////////////////////////////

    void registerCapabilites(const std::shared_ptr<ClientCapabilities> &clientCapabilites);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sasves info about the client (name and version)
    ///
    /// @param clientInfo
    ///
    //////////////////////////////////////////////////////////////
    void saveInfo(const ClientInfo &clientInfo);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Client capabilites
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ClientCapabilities> m_clientCapabilities = std::make_shared<ClientCapabilities>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Client information (name and version)
    ///
    //////////////////////////////////////////////////////////////
    ClientInfo m_clientInfo;
};
} // namespace justanlsp
