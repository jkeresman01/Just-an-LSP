#pragma once

#include <string>

#include "Message.h"

namespace lsp
{
    class NotificationMessage : Message
    {
        public:
            NotificationMessage(const std::string &method);

        private:
            std::string m_method;
    };
    
} // lsp
