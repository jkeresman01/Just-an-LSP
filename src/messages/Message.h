#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>

#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class Message
///
/// @brief A general message as defined by JSON-RPC.
///
//////////////////////////////////////////////////////////////
class Message
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Message from jsonRPC request
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    Message(const nlohmann::json &jsonRPC) : m_jsonRPC(jsonRPC["jsonrpc"]){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Serializes the message to JSON format
    ///
    /// @return Returns serialized Message in JSON format
    ///
    //////////////////////////////////////////////////////////////
    virtual nlohmann::json toJson() const;

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief RPC version, language server protocol always
    ///        uses "2.0" as the jsonrpc version
    ///
    //////////////////////////////////////////////////////////////
    std::string m_jsonRPC;
};

} // namespace justanlsp
