#pragma once

#include <memory>

#include "../params/InitializeParams.h"
#include "RequestMessage.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeRequest
///
/// @brief The initialize request is sent as the first request
///        from the client to the server.
///
//////////////////////////////////////////////////////////////
class InitializeRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Initialize request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    InitializeRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for InitalizeParams
    ///
    /// @return InitializeParams
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<InitializeParams> getInitializeParams() const { return m_initializeParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Paramters used in Initalize Request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<InitializeParams> m_initializeParams;
};
} // namespace justanlsp
