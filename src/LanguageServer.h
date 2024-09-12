#pragma once

#include <string>

#include "json.hpp"

namespace justanlsp 
{

class LanguageServer 
{
public:
    LanguageServer();

    void run();

private:
    void handleRequest(const std::string& request);
    void respond(const nlohmann::json& response);

    void logReceivedMethodRequest(const std::string& request);

    std::string readRequest();

    nlohmann::json parseRequest(const std::string& content);
};

} // justanlsp 
