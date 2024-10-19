#pragma once

#include <nlohmann/json.hpp>

#include <string>

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

    nlohmann::json parseRequest(const std::string &content);
};

} // namespace justanlsp
