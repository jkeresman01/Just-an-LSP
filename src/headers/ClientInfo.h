#pragma once

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
    };
}
