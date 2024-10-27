#pragma once

#include <string>

#include "../enums/RequestType.h"
#include "../messages/ResponseMessage.h"
#include "../utils/Convert.h"
#include "../utils/Logger.h"

namespace justanlsp
{
class Rpc
{
  public:
    Rpc() = delete;

    static void send(const ResponseMessage &response)
    {
        nlohmann::json jsonRPC = response.toJson();

        LOG_INFO << "Content length: " << jsonRPC.dump().size();
        LOG_INFO << "Content" << jsonRPC.dump(4);

        std::cout << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
        std::cout << jsonRPC.dump() << std::endl;
    }

    static std::string read()
    {
        uint32_t contentLength = readContentLength();

        std::string content(contentLength, ' ');
        std::cin.read(&content[0], contentLength);

        return content;
    }

  private:
    static uint32_t readContentLength()
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
                return contentLength;
            }
        }
    }
};
} // namespace justanlsp
