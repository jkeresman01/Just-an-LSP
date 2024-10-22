#pragma once

#include "JustAnLSPClient.h"

#include <cstdint>
#include <map>

namespace justanlsp
{

typedef std::map<uint32_t, JustAnLSPClient> JustAnLSPClientsMapT;

//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPClientService
///
/// @brief Responsible for keeping track of registered clients.
///        Implemented using Meyer's variant of Singleton pattern.
///
//////////////////////////////////////////////////////////////
class JustAnLSPClientService
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPClientService() = default;
    JustAnLSPClientService(const JustAnLSPClientService &) = delete;
    JustAnLSPClientService(JustAnLSPClientService &&) = delete;
    JustAnLSPClientService &operator=(const JustAnLSPClientService &) = delete;
    JustAnLSPClientService &operator=(JustAnLSPClientService &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the singleton instance of the JustAnLSPClientService
    ///
    //////////////////////////////////////////////////////////////
    static JustAnLSPClientService &getInstance();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Registers the new client
    ///
    /// @param client that will get registed
    ///
    //////////////////////////////////////////////////////////////
    void registerClient(const JustAnLSPClient &client);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the client by its ID
    ///
    /// @param clientId
    ///
    //////////////////////////////////////////////////////////////
    void getClientById(uint32_t clientId) const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Registered clients mapped by their coressponding IDs
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPClientsMapT m_registeredClients;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Id that will be given to client upon registration
    ///
    //////////////////////////////////////////////////////////////
    static uint32_t m_clientId;
};

} // namespace justanlsp
