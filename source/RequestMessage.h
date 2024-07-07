#pragma once

#include <cstdint>

#include "Message.h"
#include "json.hpp"

namespace lsp
{

class RequestMessage : Message
{
    RequestMessage(const std::string& jsonRPC,
                   const std::string& method,
                   int32_t id);

    nlohmann::json toJson() const override;
    
    private:
        int32_t m_id;
        std::string m_method;
};

} // lsp
