#pragma once

#include <sstream>
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct ClientInfo
///
/// @brief Stores the information about the client (editor)
///
//////////////////////////////////////////////////////////////
struct ClientInfo
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The name of the client as defined by the client
    ///
    //////////////////////////////////////////////////////////////
    std::string name;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The Client's version as defined by the client
    ///
    //////////////////////////////////////////////////////////////
    std::string version;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of Client Info
    ///
    /// @return String representation of Client Info
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        std::stringstream ss;
        ss << "Client: " << name;
        ss << ", version: " << version;
        return ss.str();
    }
};
} // namespace justanlsp
