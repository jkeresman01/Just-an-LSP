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

    while (true)
    {
        std::string message = Rpc::read();
        if (message.empty())
        {
            LOG_ERROR << "Empty message or failed to read input. Exiting the loop.";
            break; // Exit the loop if no more input
        }
        // Process the message
        handleRequest(message); // Replace with your message handler
    }
}

void JustAnLSPServer::handleRequest(const std::string &request)
{
    nlohmann::json jsoRPC = MessageUtil::tryParse(request);
    m_justAnLspFacade->handleRequest(jsoRPC);
}

} // namespace justanlsp
