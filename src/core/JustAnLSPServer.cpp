#include "JustAnLSPServer.h"

#include <string>

#include "../rpc/Rpc.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"

namespace justanlsp
{

JustAnLSPServer::JustAnLSPServer()
{
    LOG_INFO << "Instance of JustAnLSP server successfully created";
}

JustAnLSPServer::~JustAnLSPServer()
{
    LOG_INFO << "Successfull shutdown of JustAnLSP server";
}

void JustAnLSPServer::run()
{
    LOG_INFO << "JustAnLSP server successfully started";

   for(;;)
    {
        std::string message = Rpc::read();
        handleRequest(message);
    }
}

void JustAnLSPServer::handleRequest(const std::string &request)
{
    nlohmann::json jsoRPC = MessageUtil::tryParse(request);
    m_justAnLspFacade->handleRequest(jsoRPC);
}

} // namespace justanlsp
