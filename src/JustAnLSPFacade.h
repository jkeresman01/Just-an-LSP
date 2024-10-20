#pragma once

#include <memory>
#include <string>

#include "Client.h"
#include "ResponseMessage.h"

namespace justanlsp
{

class JustAnLSPFacade
{
  public:
    JustAnLSPFacade() = default;

    ResponseMessage handleRequest(const std::string &request);

  private:
    ResponseMessage handleInitializeRequest(const std::string &request);
    ResponseMessage handleTextDocumentDidOpenRequest(const std::string &request);
    ResponseMessage handleTextDocumentDidChangeRequest(const std::string &request);

  private:
    std::shared_ptr<Client> m_client = std::make_shared<Client>();
};

} // namespace justanlsp
