#pragma once

#include "RequestMessage.h"

namespace justanlsp
{

    //////////////////////////////////////////////////////////////
    ///
    /// @class InitializeRequest 
    ///
    /// @brief 
    ///
    //////////////////////////////////////////////////////////////
    class InitializeRequest : public RequestMessage
    {
        public: 
            InitializeRequest(const nlohmann::json &jsonRPC);

        private:
            InitializeParams m_initializeParams;
    };
}
