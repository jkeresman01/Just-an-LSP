#include "JustAnLSPServer.h"

#include <string>

#include "../utils/Logger.h"
#include "../utils/RequestUtil.h"
#include "../utils/ResponseUtil.h"

namespace justanlsp
{

JustAnLSPServer::JustAnLSPServer()
{
    m_justAnLspFacade = std::make_shared<JustAnLSPFacade>();

    LOG_INFO << "Instance of Language server successfully created";
}

void JustAnLSPServer::run()
{
    LOG_INFO << "Language server successfully started";

    for (;;)
    {
        std::string request = RequestUtil::readRequest();
        handleRequest(request);
    }
}

void JustAnLSPServer::handleRequest(const std::string &request)
{
    ResponseMessage response = m_justAnLspFacade->handleRequest(request);
    sendResponse(response);
}

void JustAnLSPServer::sendResponse(const ResponseMessage &response)
{
    nlohmann::json jsonRPC = response.toJson();
    ResponseUtil::sendResponse(jsonRPC);
}

} // namespace justanlsp
