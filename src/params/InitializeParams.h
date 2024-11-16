#pragma once

#include <cstdint>
#include <locale>
#include <memory>
#include <optional>
#include <string>
#include <nlohmann/json.hpp>

#include "../capabilities/ClientCapabilites.h"
#include "../enums/TraceValue.h"
#include "../types/ClientInfo.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeParams
///
/// @brief Parameters for the Initialize Request, first request
///        send from client (editor) to server
///
//////////////////////////////////////////////////////////////
class InitializeParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the InitializeParams from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit InitializeParams(const nlohmann::json &jsonInitializeParams);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for Client information
    ///
    /// @return ClientInfo
    ///
    //////////////////////////////////////////////////////////////
    ClientInfo getClientInfo() const { return m_clientInfo; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for Client capabilities
    ///
    /// @return ClientCapabilities
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ClientCapabilities> getClientCapabilites() const { return m_capabilities; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting and validataing processId
    ///
    /// @param jsoRPC
    ///
    //////////////////////////////////////////////////////////////
    void setProccessId(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting and validataing locale
    ///
    /// @param jsoRPC
    ///
    //////////////////////////////////////////////////////////////
    void setLocale(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting and validataing clientInfo
    ///
    /// @param jsoRPC
    ///
    //////////////////////////////////////////////////////////////
    void setClientInfo(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting and validataing trace level
    ///
    /// @param jsoRPC
    ///
    //////////////////////////////////////////////////////////////
    void setTraceLevel(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The process Id of the parent process that started
    ///        the server. Is null if the process has not been
    ///        started by another process. If the parent process
    ///        is not alive then the server should exit
    ///        (see exit notification) its process
    ///
    //////////////////////////////////////////////////////////////
    std::optional<int64_t> m_processId;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Information about the client
    ///
    /// @since 3.15.0
    ///
    //////////////////////////////////////////////////////////////
    ClientInfo m_clientInfo;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The locale the client is currently showing the user
    ///        interface in. This must not necessarily be the
    ///        locale of the operating system
    ///
    /// @since 3.16.0
    ///
    //////////////////////////////////////////////////////////////
    std::string m_locale;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The capabilities provided by the client (editor or tool)
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ClientCapabilities> m_capabilities;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The initial trace setting.
    ///        If omitted trace is disabled ('off')
    ///
    //////////////////////////////////////////////////////////////
    TraceValue m_traceValue;
};

} // namespace justanlsp
