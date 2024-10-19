#pragma once

#include <cstdint>

#include "ClientInfo.h"

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
            InitializeParams(const nlohmann::json &jsonRPC);

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
            int64_t m_processId;

            //////////////////////////////////////////////////////////////
            ///
            /// @brief Information about the client
            ///
            /// @since 3.15.0
            ///
            //////////////////////////////////////////////////////////////
            ClientInfo m_clientInfo;
    };

}
