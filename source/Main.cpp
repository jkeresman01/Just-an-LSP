#include <iostream>
#include "json.hpp"
#include "Logger.h"

using json = nlohmann::json;

std::string readMessage() 
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

void logReceviedMessage(const std::string &jsonMessage)
{
    json message = json::parse(jsonMessage);
    if (message.find("method") != message.end()) 
    {
        std::string method = std::string(message["method"]);
        lsp::LOG_INFO("Received request with method: " + method);
    }
}

int main() 
{
    lsp::LOG_INFO("Language server has successfully started!");

    while (true) 
    {
        std::string content = readMessage();

        try 
        {
            logReceviedMessage(content);
        } 
        catch (const json::parse_error& e) 
        {
            lsp::LOG_ERROR(std::string("JSON parse error: ") + e.what());
        }
    }

}
