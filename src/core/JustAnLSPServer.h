#pragma once

#include <nlohmann/json.hpp>

#include <memory>
#include <string>

#include "../messages/ResponseMessage.h"
#include "JustAnLSPFacade.h"

namespace justanlsp
{

class LanguageServer
{
  public:
    LanguageServer();

    void run();

  private:
    void handleRequest(const std::string &request);
    void sendResponse(const ResponseMessage &response);

  private:
    std::shared_ptr<JustAnLSPFacade> m_justAnLspFacade;
};

} // namespace justanlsp
