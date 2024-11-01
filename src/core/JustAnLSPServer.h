#pragma once

#include <nlohmann/json.hpp>

#include <memory>
#include <string>

#include "../messages/response/ResponseMessage.h"
#include "JustAnLSPFacade.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPServer
///
/// @brief JustAnLSP entry class, responsible for starting the server
///
//////////////////////////////////////////////////////////////
class JustAnLSPServer
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs (creates instance) of the JustAnLSPServer
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPServer();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Starts the JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    void run();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Stops the JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    void stop();

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Distributes requests to JustAnLSP facade
    ///
    //////////////////////////////////////////////////////////////
    void handleRequest(const std::string &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Single simplified interface for handling JustAnLspLSP
    ///        request messages
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<JustAnLSPFacade> m_justAnLspFacade = std::make_shared<JustAnLSPFacade>();
};

} // namespace justanlsp
