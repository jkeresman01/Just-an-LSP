#pragma once

#include <memory>

#include "../CodeActions/ICodeActionsProvider.h"
#include "../Completions/ICompletionProvider.h"
#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Messages/Request/CodeActionRequest.h"
#include "../Messages/Request/CompletionRequest.h"
#include "../Messages/Request/DefinitionRequest.h"
#include "../Messages/Request/DidChangeTextDocumentRequest.h"
#include "../Messages/Request/DidOpenTextDocumentRequest.h"
#include "../Messages/Request/HoverRequest.h"
#include "../Messages/Request/InitializeRequest.h"
#include "../Messages/Request/ShutdownRequest.h"
#include "../Snippets/ISnippetProvider.h"
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
    JustAnLSPReqHandler();
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
    void textDocumentCodeActionReq(const std::shared_ptr<CodeActionRequest> &codeActionRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/definition request
    ///
    /// @param textDocument/definition request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDefinitionReq(const std::shared_ptr<DefintionRequest> &defintionRequest);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief JustAnLSPClient - editor or tool attached to
    ///        JustAnLSP server
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPClient> m_justAnLSPClient = std::make_unique<JustAnLSPClient>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to completions provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ICompletionProvider> m_completionProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to diagnostics provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IDiagnosticsProvider> m_diagnosticsProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to code actions provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ICodeActionsProvider> m_codeActionsProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to snippets provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ICodeActionsProvider> m_snippetsProvider;
};
} // namespace justanlsp
