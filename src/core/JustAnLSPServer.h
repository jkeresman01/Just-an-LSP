#pragma once

#include <memory>
#include <nlohmann/json.hpp>
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
    JustAnLSPServer() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Tilda Swilton (destructs JustAnLSP server)
    ///
    //////////////////////////////////////////////////////////////
    ~JustAnLSPServer() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Starts the JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    void run();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Initializes the JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    void init();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Shutdown of the JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    void shutdown();

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
