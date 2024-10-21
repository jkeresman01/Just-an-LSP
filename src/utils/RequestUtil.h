#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../enums/RequestType.h"
#include "Logger.h"
#include "RequestMethodUtil.h"

namespace justanlsp
{
class RequestUtil
{
  public:
    RequestUtil() = delete;

    static std::string readRequest()
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
            LOG_ERROR << "No valid content length found, can't read the payload!";
            return "";
        }

        std::string content(contentLength, ' ');
        std::cin.read(&content[0], contentLength);

        return content;
    }

    static RequestType getType(const nlohmann::json &request)
    {
        auto it = request.find("method");
        if (it == request.end())
        {
            LOG_ERROR << "Received unknown request type";
            return RequestType::UNKNOWN;
        }

        std::string method = std::string(request["method"]);
        return RequestMethodUtil::getType(method);
    }

    static nlohmann::json tryParse(const std::string &request)
    {
        nlohmann::json jsonRequest;
        try
        {
            jsonRequest = nlohmann::json::parse(request);
        }
        catch (const std::exception &e)
        {
            LOG_ERROR << "Failed to parse request: " << std::string(e.what()) << "!";
        }

        return jsonRequest;
    }
};
} // namespace justanlsp
