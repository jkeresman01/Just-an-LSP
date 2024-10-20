#pragma once

#include <string>

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
};

} // namespace justanlsp
