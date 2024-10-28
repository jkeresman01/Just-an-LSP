#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>
#include <ostream>
#include <set>
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
    /// @brief Constructs the Message from jsonRPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    Message(const std::string &jsonRPC) : m_jsonRPC(jsonRPC){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Serializes the message to JSON format
    ///
    /// @return Returns serialized Message in JSON format
    ///
    //////////////////////////////////////////////////////////////
    virtual nlohmann::json toJson() const { return {{"jsonrpc", m_jsonRPC}}; }

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
