#pragma once

#include "../capabilities/ServerCapabilities.h"
#include "../types/ServerInfo.h"
#include "ResponseMessage.h"

namespace justanlsp
{

class InitializeResponse : public Message
{
  public:
    InitializeResponse(const ServerInfo &serverInfo, const ServerCapabilities &serverCapabilites);

    nlohmann::json toJson() const;

  private:
    ServerInfo m_serverInfo;
    ServerCapabilities m_serverCapabilites;
};

} // namespace justanlsp
