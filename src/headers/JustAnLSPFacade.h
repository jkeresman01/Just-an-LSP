#pragma once

#include "RequestMessage.h"

namespace justanlsp
{

class JustAnLSPFacade
{
  public:
    JustAnLSPFacade() = default;
    void handleRequest(const RequestMessage &requestMessage);
};

} // namespace justanlsp
