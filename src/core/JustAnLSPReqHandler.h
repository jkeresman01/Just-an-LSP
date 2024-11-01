#pragma once

#include <memory>

#include "../messages/request/DidOpenTextDocumentRequest.h"
#include "../messages/request/InitializeRequest.h"
#include "../messages/request/ShutdownRequest.h"
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
    /// @brief textDocument/didOpen request
    ///
    /// @param textDocument/didOpen request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDidOpenReq(const std::shared_ptr<DidOpenTextDocumentRequest> &didOpenTextDocumentReq);
};
} // namespace justanlsp
