#pragma once

#include <sstream>
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct ServerInfo
///
/// @brief Stores the information about the server
///
/// @since 3.15.0
///
//////////////////////////////////////////////////////////////
struct ServerInfo
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The name of the server as defined by the server
    ///
    //////////////////////////////////////////////////////////////
    std::string name;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The Server's version as defined by the server
    ///
    //////////////////////////////////////////////////////////////
    std::string version;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of ServerInfo
    ///
    /// @return String representation of ServerInfo
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        std::stringstream ss;
        ss << "Server: " << name;
        ss << ", version: " << version;
        return ss.str();
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes ServerInfo to JSON
    ///
    /// @return Serializes ServerInfo to JSON
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const
    {
        nlohmann::json serverInfoJson = {{"name", name}, {"version", version}};
        return serverInfoJson;
    }
};
} // namespace justanlsp
