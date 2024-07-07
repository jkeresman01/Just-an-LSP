#include "LanguageServer.h"

#include "Logger.h"

namespace lsp 
{

LanguageServer::LanguageServer()
{
    LOG_INFO("Instace of Language server was successfully created!");
}

void LanguageServer::run() 
{
    LOG_INFO("Language server has successfully started!");

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
        LOG_ERROR("No valid content length found, can't read the payload!");
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
        logReceivedMethodRequest(request);
    } 
    catch (const std::exception& e) 
    {
        LOG_ERROR("Failed to handle request: " + std::string(e.what()));
    }
}

void LanguageServer::logReceivedMethodRequest(const std::string& request)
{
    auto jsonRequest = parseRequest(request);

    if(jsonRequest.find("method") == jsonRequest.end())
    {
        LOG_ERROR("Received request with no method!");
        return;
    }

    std::string method = std::string(jsonRequest["method"]);
    LOG_INFO("Received request with method: " + method);
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

