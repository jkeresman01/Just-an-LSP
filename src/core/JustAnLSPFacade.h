#pragma onceFaca

#include <memory>
#include <string>

#include "../messages/ResponseMessage.h"
#include "JustAnLSPClient.h"

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
    ResponseMessage handleTextDocumentHoverRequest(const std::string &request);
    ResponseMessage handleTextDocumentDidChangeRequest(const std::string &request);

  private:
    std::shared_ptr<JustAnLSPClient> m_client = std::make_shared<JustAnLSPClient>();
};

} // namespace justanlsp
