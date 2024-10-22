#include "JustAnLSPServer.h"

#include <string>

#include "../rpc/Rpc.h"
#include "../utils/Logger.h"

namespace justanlsp
{

JustAnLSPServer::JustAnLSPServer()
{
    m_justAnLspFacade = std::make_shared<JustAnLSPFacade>();

    LOG_INFO << "Instance of JustAnLSP server successfully created";
}

JustAnLSPServer::~JustAnLSPServer()
{
    LOG_INFO << "Successfull shutdown of JustAnLSP server";
}

void JustAnLSPServer::run()
{
    LOG_INFO << "JustAnLSP server successfully started";

    for (;;)
    {
        std::string request = Rpc::read();
        handleRequest(request);
    }
}

void JustAnLSPServer::handleRequest(const std::string &request)
{
    m_justAnLspFacade->handleRequest(request);
}

} // namespace justanlsp
