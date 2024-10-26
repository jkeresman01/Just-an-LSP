#pragma once

#include <string>

#include "../enums/RequestType.h"
#include "../messages/ResponseMessage.h"
#include "../utils/Logger.h"

namespace justanlsp
{
class Rpc
{
  public:
    Rpc() = delete;

    static std::string read()
    {
        LOG_INFO << "Starting to read new message ..";

        std::string header;
        uint32_t contentLength = 0;

        while (getline(std::cin, header))
        {
            LOG_INFO << "Received header line: '" << header << "'";

            header.erase(0, header.find_first_not_of(" \t\r\n\v\f"));
            header.erase(header.find_last_not_of(" \t\r\n\v\f") + 1);

            if (header.substr(0, 16) == "Content-Length: ")
            {
                contentLength = std::stoul(header.substr(16));
                LOG_INFO << "Extracted Content-Length: " << contentLength;
            }

            if (header.empty())
            {
                LOG_INFO << "End of headers reached.";
                break;
            }
        }

        if (contentLength == 0)
        {
            LOG_ERROR << "No valid content length found, can't read the payload!";
            return "";
        }

        LOG_INFO << "Reading message content with length: " << contentLength;
        std::string content(contentLength, ' ');
        std::cin.read(&content[0], contentLength);

        if (!std::cin)
        {
            LOG_ERROR << "Error occurred while reading message content.";
            return "";
        }

        LOG_INFO << "Successfully read message content: " << content;

        return content;
    }

    static void send(const ResponseMessage &response)
    {
        nlohmann::json jsonRPC = response.toJson();

        LOG_INFO << "Content length: " << jsonRPC.dump().size();
        LOG_INFO << "Content" << jsonRPC.dump(4);

        std::cout << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
        std::cout << jsonRPC.dump() << std::endl;
    }
};
} // namespace justanlsp
