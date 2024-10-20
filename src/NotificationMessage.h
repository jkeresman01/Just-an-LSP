#pragma once

#include <string>

#include "Message.h"

namespace justanlsp
{

class NotificationMessage : public Message
{
  public:
    NotificationMessage(const std::string &method, const std::string &jsonRPC);

  private:
    std::string m_method;
};

} // namespace justanlsp
