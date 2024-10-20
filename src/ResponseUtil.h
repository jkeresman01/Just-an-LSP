#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ResponseMessage.h"
#include "Logger.h"

namespace justanlsp
{
class ResponseUtil
{
  public:
    ResponseUtil() = delete;

    static void sendResponse(const nlohmann::json &response)
    {
        LOG_INFO << "Sending response: " << response.dump(4);

        std::cout << "Content-Length: " << response.dump().size() << "\r\n\r\n";
        std::cout << response.dump() << std::endl;
    }
};
} // namespace justanlsp
