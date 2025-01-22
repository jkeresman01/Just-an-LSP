#include "JustAnLSPServer.h"

#include <memory>
#include <string>

#include "../rpc/Rpc.h"
#include "../utils/Logger.h"
#include "../utils/MessageUtil.h"
#include "JustAnLSPFacade.h"

namespace justanlsp
{

void JustAnLSPServer::init()
{
    LOG_INFO("Initilalizing JustAnLSP server");
}

void JustAnLSPServer::shutdown()
{
    LOG_INFO("Successfull shutdown of JustAnLSP server");
}

void JustAnLSPServer::run()
{
    LOG_INFO("JustAnLSP server successfully started");

    for (;;)
    {
        handleRequest(Rpc::receive());
    }
}

void JustAnLSPServer::handleRequest(const std::string &request)
{
    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
    m_justAnLspFacade->handleRequest(jsonRPC);
}

} // namespace justanlsp
