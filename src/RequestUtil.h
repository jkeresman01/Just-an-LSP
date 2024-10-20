#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "Logger.h"
#include "RequestType.h"

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

    static RequestType getRequestType(const nlohmann::json &request)
    {
        auto it = request.find("method");

        if (it == request.end())
        {
            LOG_ERROR << "Received unknown request type";
            return RequestType::UNKNOWN;
        }

        std::string method = std::string(request["method"]);
        LOG_INFO << "Received request with method: " << method << "!";

        return mapMethodToRequestType(method);
    }

    static nlohmann::json tryParse(const std::string &request)
    {
        nlohmann::json jsonRequest;

        try
        {
            jsonRequest = nlohmann::json::parse(request);
            LOG_INFO << "Trying to parse request" << jsonRequest.dump(4);
        }
        catch (const std::exception &e)
        {
            LOG_ERROR << "Failed to parse request: " << std::string(e.what()) << "!";
        }

        return jsonRequest;
    }

  private:
    static RequestType mapMethodToRequestType(const std::string &method)
    {
        if (method == "initalize")
        {
            return RequestType::INITIALIZE;
        }
        else if (method == "textDocumentDidChange")
        {
            return RequestType::TEXT_DOCUMENT_DID_CHANGE;
        }
        else if (method == "textDocumentDidOpen")
        {
            return RequestType::TEXT_DOCUMENT_DID_OPEN;
        }
        else if (method == "textDocumentHover")
        {
            return RequestType::TEXT_DOCUMENT_HOVER;
        }
        else
        {
            return RequestType::UNKNOWN;
        }
    }
};
} // namespace justanlsp
