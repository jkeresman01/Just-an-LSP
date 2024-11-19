#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "../messages/response/ResponseMessage.h"
#include "JustAnLSPClient.h"
#include "JustAnLSPCounter.h"
#include "JustAnLSPErrorHandler.h"
#include "JustAnLSPReqHandler.h"

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
    void handleRequest(const nlohmann::json &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialize request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializeRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling shutdown request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleShutdownRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialized request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializedRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didOpen request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidOpenRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didChange request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidChangeRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/hover request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentHoverRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCompletionRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleExitRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCodeActionRequest(const nlohmann::json &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Ensures no request is processed after shudtown request
    ///        has been received, except exit notification
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void ensureNoReqIsProcessedAfterShutdown(const nlohmann::json &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Responsible for handling request such as init/shutdown
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPReqHandler> m_justAnLSPReqHandler = std::make_unique<JustAnLSPReqHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Responsible for handling request such as init/shutdown
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPErrorHandler> m_justAnLSPErrorHandler =
        std::make_unique<JustAnLSPErrorHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Request counters
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPCounter> m_justAnLspCounters = std::make_unique<JustAnLSPCounter>();
};

} // namespace justanlsp
