#pragma once

#include "../messages/Message.h"

#include <cstdint>
#include <nlohmann/json.hpp>

namespace justanlsp
{
class ResponseMessage : public Message
{
  public:
    ResponseMessage(const std::string &jsonRpc, const int64_t id) : Message(jsonRpc), m_id(id){};

    nlohmann::json toJson() const;

  private:
    int64_t m_id;
};
} // namespace justanlsp
