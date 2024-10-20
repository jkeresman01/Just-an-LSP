#include "JustAnLSPServer.h"

#include <string>

#include "RequestUtil.h"
#include "ResponseUtil.h"
#include "Logger.h"

namespace justanlsp
{

LanguageServer::LanguageServer()
{
    LOG_INFO << "Instace of Language server successfully created";
}

void LanguageServer::run()
{
    LOG_INFO << "Language server successfully started";

    for (;;)
    {
        std::string request = RequestUtil::readRequest();
        handleRequest(request);
    }
}

void LanguageServer::handleRequest(const std::string &request)
{
    ResponseMessage response = m_justAnLspFacade->handleRequest(request);
    sendResponse(response);
}

void LanguageServer::sendResponse(const ResponseMessage &response)
{
    nlohmann::json jsonRPC = response.toJson();
    ResponseUtil::sendResponse(jsonRPC);
}

} // namespace justanlsp
