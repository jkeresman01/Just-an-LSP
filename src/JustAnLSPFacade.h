#pragma once

#include <string>

#include "RequestMessage.h"

namespace justanlsp
{

class JustAnLSPFacade
{
  public:
    JustAnLSPFacade() = default;

    void handleRequest(const std::string &request);
};

} // namespace justanlsp
