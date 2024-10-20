#pragma once

#include <nlohmann/json.hpp>

#include <memory>
#include <string>

#include "JustAnLSPFacade.h"
#include "ResponseMessage.h"

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
    std::shared_ptr<JustAnLSPFacade> m_justAnLspFacade = std::make_shared<JustAnLSPFacade>();
};

} // namespace justanlsp
