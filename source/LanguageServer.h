#pragma once

#include <string>

#include "json.hpp"

namespace lsp 
{

class LanguageServer 
{
public:
    LanguageServer();

    void run();

private:
    void handleRequest(const std::string& request);
    void respond(const nlohmann::json& response);

    std::string readRequest();

    nlohmann::json parseRequest(const std::string& content);
};

} // lsp

