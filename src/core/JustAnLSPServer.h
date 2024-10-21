#pragma once

#include <nlohmann/json.hpp>

#include <memory>
#include <string>

#include "../messages/ResponseMessage.h"
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

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Distributes requests to JustAnLSP facade
    ///
    //////////////////////////////////////////////////////////////
    void handleRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sends response to client (editor or tool)
    ///
    //////////////////////////////////////////////////////////////
    void sendResponse(const ResponseMessage &response);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Single simplified interface for handling JustAnLspLSP 
    ///        request messages
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<JustAnLSPFacade> m_justAnLspFacade;
};

} // namespace justanlsp
