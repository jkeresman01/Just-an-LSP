#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>

#include "Message.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class RequestMessage
///
/// @brief A request message to describe a request between
///        the client (editor) and the server.
///
//////////////////////////////////////////////////////////////
class RequestMessage : public Message
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the RequestMessage from json RPC
    ///
    //////////////////////////////////////////////////////////////
    RequestMessage(const nlohmann::json &jsonRPC) : Message(jsonRPC), m_id(jsonRPC["id"]){};

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The request ID
    ///
    //////////////////////////////////////////////////////////////
    int64_t m_id;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The method to be invoked
    ///
    //////////////////////////////////////////////////////////////
    std::string m_method;
};

} // namespace justanlsp
