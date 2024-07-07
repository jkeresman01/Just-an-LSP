#pragma once

#include <string>

#include "json.hpp"

namespace lsp
{

class Message
{
    public:
        Message(const std::string& jsonRPC) : m_jsonRPC(jsonRPC){};

        virtual nlohmann::json toJson() const = 0;

    protected:
        std::string m_jsonRPC;
};
    
}// lsp

