#pragma once

#include <cstdint>

#include "Message.h"
#include "json.hpp"

namespace lsp
{
    class RequestMessage : Message
    {
        RequestMessage(int32_t id, const std::string& method);

        nlohmann::json toJson() const override;
        
        private:
            int32_t m_id;
            std::string m_method;
    };
    
} // lsp
