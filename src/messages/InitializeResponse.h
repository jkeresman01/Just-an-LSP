#pragma once

#include "../capabilities/ServerCapabilities.h"
#include "../types/ServerInfo.h"
#include "ResponseMessage.h"
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeResponse
///
/// @brief Represents the response to an "initialize" request
///        in the language server protocol (LSP).
///
//////////////////////////////////////////////////////////////
class InitializeResponse : public ResponseMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs an InitializeResponse with the provided
    ///        server info and capabilities.
    ///
    /// @param serverInfo
    /// @param serverCapabilities
    ///
    //////////////////////////////////////////////////////////////
    InitializeResponse(const ServerInfo &serverInfo, const ServerCapabilities &serverCapabilities);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the InitializeResponse to JSON format.
    ///
    /// @return Returns the response in JSON format.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of InitializeResponse
    ///
    /// @brief String representation of InitializeResponse
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Information about the server, such as its name and version.
    ///
    //////////////////////////////////////////////////////////////
    ServerInfo m_serverInfo;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The server's capabilities, which define what the server can do.
    ///
    //////////////////////////////////////////////////////////////
    ServerCapabilities m_serverCapabilities;
};

} // namespace justanlsp
