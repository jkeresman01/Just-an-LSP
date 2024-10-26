#pragma once

#include "../capabilities/ServerCapabilities.h"
#include "../types/ServerInfo.h"
#include "ResponseMessage.h"
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeResult
///
/// @brief Represents the response to an "initialize" request
///        in the language server protocol (LSP).
///
//////////////////////////////////////////////////////////////
class InitializeResult
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs an InitializeResult with the provided
    ///        server info and capabilities.
    ///
    /// @param serverInfo
    /// @param serverCapabilities
    ///
    //////////////////////////////////////////////////////////////
    InitializeResult(const ServerInfo &serverInfo, const ServerCapabilities &serverCapabilities);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the InitializeResult to JSON format.
    ///
    /// @return Returns the response in JSON format.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of InitializeResult
    ///
    /// @brief String representation of InitializeResult
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
