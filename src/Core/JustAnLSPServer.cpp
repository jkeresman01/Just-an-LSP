#include "JustAnLSPServer.h"

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "../Rpc/Rpc.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"
#include "JustAnLSPFacade.h"

namespace justanlsp
{

void JustAnLSPServer::init()
{
    ConfigurationManager::getInstance()->load();

    JLSP_DEBUG("Initializing JustAnLSP server");
}

void JustAnLSPServer::shutdown()
{
    JLSP_DEBUG("Successful shutdown of JustAnLSP server");
}

void JustAnLSPServer::run()
{
    JLSP_DEBUG("JustAnLSP server successfully started");

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
