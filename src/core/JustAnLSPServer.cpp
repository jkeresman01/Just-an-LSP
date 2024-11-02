#include "JustAnLSPServer.h"

#include <memory>
#include <string>

#include "../rpc/Rpc.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"
#include "JustAnLSPFacade.h"

namespace justanlsp
{

JustAnLSPServer::JustAnLSPServer()
{
    LOG_INFO("Instance of JustAnLSP server successfully created");
}

JustAnLSPServer::~JustAnLSPServer()
{
    LOG_INFO("Tilda Swilton - Successfull shutdown of JustANLSPServer!");
}

void JustAnLSPServer::run()
{
    LOG_INFO("JustAnLSP server successfully started");

    for (;;)
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
