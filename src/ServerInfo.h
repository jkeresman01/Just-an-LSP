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
    std::string toString()
    {
        std::stringstream ss;
        ss << "Server: " << name;
        ss << ", version: " << version << std::endl;
        return ss.str();
    }
};
}
