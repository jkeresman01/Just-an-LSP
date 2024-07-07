#include "LanguageServer.h"

#include "Logger.h"

namespace lsp 
{

LanguageServer::LanguageServer()
{
    LOG_INFO("Language server has successfully started!");
}

void LanguageServer::run() {
    while (true) 
    {
        std::string request = readRequest();
        handleRequest(request);
    }
}

std::string LanguageServer::readRequest()
{
    std::string header;
    uint32_t contentLength = 0;

    while (getline(std::cin, header)) 
    {
        header.erase(0, header.find_first_not_of(" \t\r\n\v\f"));
        header.erase(header.find_last_not_of(" \t\r\n\v\f") + 1);

        if (header.substr(0, 16) == "Content-Length: ") 
        {
            contentLength = std::stoul(header.substr(16));
        }

        if (header.empty()) { break; }
    }

    if (contentLength == 0) 
    {
        lsp::LOG_ERROR("No valid content length found!");
        return "";
    }

    std::string content(contentLength, ' ');
    std::cin.read(&content[0], contentLength);

    return content;

}

void LanguageServer::handleRequest(const std::string& request) 
{
    try 
    {
        auto jsonRequest = parseRequest(request);
        if (jsonRequest.find("method") != jsonRequest.end()) 
        {
            std::string method = std::string(jsonRequest["method"]);
            lsp::LOG_INFO("Received request with method: " + method);
        }

        //TODO: call responde based on appropriate message
    } 
    catch (const std::exception& e) 
    {
        LOG_ERROR("Failed to handle request: " + std::string(e.what()));
    }
}

nlohmann::json LanguageServer::parseRequest(const std::string& content) 
{
    return nlohmann::json::parse(content);
}

void LanguageServer::respond(const nlohmann::json& response) 
{
    std::cout << "Content-Length: " << response.dump().size() << "\r\n\r\n";
    std::cout << response.dump() << std::endl;
}

} // lsp

