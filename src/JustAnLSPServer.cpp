#include "JustAnLSPServer.h"

#include <memory>
#include <string>

#include "Logger.h"
#include "RequestUtil.h"
#include "ResponseUtil.h"

namespace justanlsp
{

LanguageServer::LanguageServer()
{
    m_justAnLspFacade = std::make_shared<JustAnLSPFacade>();

    LOG_INFO << "Instance of Language server successfully created";
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
