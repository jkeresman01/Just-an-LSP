#pragma once

#include <string>

#include "json.hpp"

namespace justanlsp
{

enum MessageType
{
    TEXT_DOCUMENT_DID_OPEN = 0,
    TEXT_DOCUMENT_DID_CHANGE = 1,
    INVALID_MESSAGE_TYPE = 2,
};

class LanguageServer
{
  public:
    LanguageServer();

    void run();

  private:
    void handleRequest(const std::string &request);
    void handleTextDocumentDidOpen(const std::string &request);
    void handleTextDocumentDidChange(const std::string &request);

    void respond(const nlohmann::json &response);

    MessageType extractMsgType(const std::string &request);

    std::string readRequest();

    nlohmann::json parseRequest(const std::string &content);
};

} // namespace justanlsp
