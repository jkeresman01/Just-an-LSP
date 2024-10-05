#pragma once

#include <nlohmann/json.hpp>

#include <string>

namespace justanlsp
{

class Message
{
  public:
    Message(const std::string &jsonRPC) : m_jsonRPC(jsonRPC){};

    virtual nlohmann::json toJson() const;

  protected:
    std::string m_jsonRPC;
};

} // namespace justanlsp
