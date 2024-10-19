#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

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

    void handleInitializeRequest(const std::string &request);
    void handleTextDocumentDidOpenRequest(const std::string &request);
    void handleTextDocumentDidChangeRequest(const std::string &request);

    const char *msgTypeToString(const MessageType &messageType) const;

    void respond(const nlohmann::json &response);

    MessageType extractMsgType(const std::string &request);

    std::string readRequest();

  private:
    std::shared_ptr<JustAnLSPFacade> m_justAnLspFace = std::make_shared<JustAnLSPFacade>();
};

} // namespace justanlsp
