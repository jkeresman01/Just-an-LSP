#pragma once

#include <memory>

#include "../Messages/request/CompletionRequest.h"
#include "../Messages/request/DidChangeTextDocumentRequest.h"
#include "../Messages/request/DidOpenTextDocumentRequest.h"
#include "../Messages/request/HoverRequest.h"
#include "../Messages/request/InitializeRequest.h"
#include "../Messages/request/ShutdownRequest.h"
#include "JustAnLSPClient.h"
#include "JustAnLSPCounter.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPReqHandler
///
/// @brief Responsible for handling JustAnLSP requests
///        (init, shutdown, register/unregister capabilites)
///
//////////////////////////////////////////////////////////////
class JustAnLSPReqHandler
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPReqHandler() = default;
    JustAnLSPReqHandler(const JustAnLSPReqHandler &) = delete;
    JustAnLSPReqHandler(JustAnLSPReqHandler &&) = delete;
    JustAnLSPReqHandler &operator=(const JustAnLSPReqHandler &) = delete;
    JustAnLSPReqHandler &operator=(JustAnLSPReqHandler &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the initialization request
    ///
    /// @param initializeRequest
    ///
    //////////////////////////////////////////////////////////////
    void initializeReq(const std::shared_ptr<InitializeRequest> &initializeRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the shutdown request
    ///
    /// @param shutdownRequest
    ///
    //////////////////////////////////////////////////////////////
    void shutdownReq(const std::shared_ptr<ShutdownRequest> &shutdownRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/didOpen request
    ///
    /// @param textDocument/didOpen request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDidOpenReq(const std::shared_ptr<DidOpenTextDocumentRequest> &didOpenTextDocumentReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/completion request
    ///
    /// @param textDocument/completion  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentCompletionReq(const std::shared_ptr<CompletionRequest> &completionReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/didChange request
    ///
    /// @param textDocument/didChange  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDidChangeReq(
        const std::shared_ptr<DidChangeTextDocumentRequest> &didChangeTextDocumentReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/hover request
    ///
    /// @param textDocument/hover  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentHoverReq(const std::shared_ptr<HoverRequest> &hoverTextDocuementReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/codeAction request
    ///
    /// @param textDocument/codeAction  request
    ///
    //////////////////////////////////////////////////////////////
    /* void textDocumentCodeActionReq(const std::shared_ptr<CodeActionRequest> &codeActionRequest); */

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief JustAnLSPClient - editor or tool attached to
    ///        JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPClient> m_justAnLSPClient = std::make_unique<JustAnLSPClient>();
};
} // namespace justanlsp
