#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../enums/RequestType.h"
#include "Logger.h"
#include "RequestMethodUtil.h"

namespace justanlsp
{
class MessageUtil
{
  public:
    MessageUtil() = delete;

    static RequestType getType(const nlohmann::json &request)
    {
        auto it = request.find("method");

        if (it == request.end())
        {
            LOG_ERROR("Received unknown request type");
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
            LOG_ERROR(STR("Failed to parse request: %s!", e.what()));
        }

        return jsonRequest;
    }
};
} // namespace justanlsp
