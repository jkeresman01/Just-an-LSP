#include "headers/JustAnLSPServer.h"

#include <string>

#include "headers/Logger.h"

namespace justanlsp
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

        if (header.empty())
        {
            break;
        }
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

void LanguageServer::handleRequest(const std::string &request)
{
    MessageType messageType = extractMsgType(request);

    switch (messageType)
    {
    case TEXT_DOCUMENT_DID_OPEN:
        handleTextDocumentDidOpen(request);
        break;
    case TEXT_DOCUMENT_DID_CHANGE:
        handleTextDocumentDidChange(request);
        break;
    default:
        /* LOG_ERROR("Received unkown request: " <<  msgTypeToString(messageType) << "!") */
        break;
    }
}

void LanguageServer::handleTextDocumentDidOpen(const std::string &request)
{
    // TODO
    (void)request;
}

void LanguageServer::handleTextDocumentDidChange(const std::string &request)
{
    // TODO
    (void)request;
}

MessageType LanguageServer::extractMsgType(const std::string &request)
{
    try
    {
        auto jsonRequest = nlohmann::json::parse(request);
        auto it = jsonRequest.find("method");
        if (it == jsonRequest.end())
        {
            LOG_ERROR("Received invalid reqest");
            return INVALID_MESSAGE_TYPE;
        }

        std::string method = std::string(jsonRequest["method"]);
        LOG_INFO("Received request with method: " + method);
        LOG_INFO(jsonRequest.dump(4));
    }
    catch (const std::exception &e)
    {
        LOG_ERROR("Failed to handle request: " + std::string(e.what()));
    }

    // TODO map value to correct msg type
    return INVALID_MESSAGE_TYPE;
}

void LanguageServer::respond(const nlohmann::json &response)
{
    std::cout << "Content-Length: " << response.dump().size() << "\r\n\r\n";
    std::cout << response.dump() << std::endl;
}

const char *LanguageServer::msgTypeToString(const MessageType &messageType) const
{
    switch (messageType)
    {
    case TEXT_DOCUMENT_DID_OPEN:
        return "textDocumentDidOpen";
    case TEXT_DOCUMENT_DID_CHANGE:
        return "textDocumentDidChange";
    default:
        return "ivalidMessageType";
    }
}

} // namespace justanlsp
