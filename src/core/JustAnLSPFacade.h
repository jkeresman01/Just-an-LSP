#pragma once

#include "JustAnLSPClient.h"
#include "JustAnLSPReqHandler.h"

#include <memory>
#include <string>

#include "../messages/ResponseMessage.h"
#include "JustAnLSPClient.h"
#include "JustAnLSPCounter.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPFacade
///
/// @brief Single simplified interface for handling JustAnLspLSP
///        request messages
///
//////////////////////////////////////////////////////////////
class JustAnLSPFacade
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPFacade() = default;
    JustAnLSPFacade(const JustAnLSPFacade &) = delete;
    JustAnLSPFacade(JustAnLSPFacade &&) = delete;
    JustAnLSPFacade &operator=(const JustAnLSPFacade &) = delete;
    JustAnLSPFacade &operator=(JustAnLSPFacade &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Interface for handling all LSP requests
    ///
    /// @param String representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleRequest(const std::string &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialize request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializeRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling shutdown request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleShutdownRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialized request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializedRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didOpen request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleTextDocumentDidOpenRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didChange request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidChangeRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/hover request
    ///
    /// @param string representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentHoverRequest(const std::string &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Responsible for handling request such as init/shutdown
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPReqHandler> m_justAnLSPReqHandler = std::make_unique<JustAnLSPReqHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Request counters
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPCounter> m_justAnLspCounters = std::unique_ptr<JustAnLSPCounter>();
};

} // namespace justanlsp
