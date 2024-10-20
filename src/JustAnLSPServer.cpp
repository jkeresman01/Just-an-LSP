#include "JustAnLSPServer.h"

#include <string>

#include "Logger.h"
#include "RequestUtil.h"

namespace justanlsp
{

LanguageServer::LanguageServer()
{
    LOG_INFO("Instace of Language server successfully created!");
}

void LanguageServer::run()
{
    LOG_INFO("Language server successfully started!");

    for (;;)
    {
        std::string request = RequestUtil::readRequest();
        handleRequest(request);
    }
}

void LanguageServer::handleRequest(const std::string &request)
{
    LOG_INFO("Responding on the request with method: ");
    LOG_INFO(RequestUtil::getRequestType(request));


    ResponseMessage response = m_justAnLspFacade->handleRequest(request);
    sendResponse(response);
}

void LanguageServer::sendResponse(const ResponseMessage &response)
{
    nlohmann::json jsonRPC = response.toJson();

    LOG_INFO("Sending response: ");
    LOG_INFO(jsonRPC.dump(4));

    std::cout << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    std::cout << jsonRPC.dump() << std::endl;
}

} // namespace justanlsp
