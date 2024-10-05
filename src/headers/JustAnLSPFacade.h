#pragma once

#include "RequestMessage.h"

namespace justanlsp
{
class JustAnLSPFacade
{
  public:
    void handleRequest(const RequestMessage &requestMessage);
};
} // namespace justanlsp
