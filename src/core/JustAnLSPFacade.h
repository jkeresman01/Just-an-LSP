#include "JustAnLSPClient.h"
#pragma onceFaca

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
    ResponseMessage handleRequest(const std::string &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialize request
    ///
    /// @param string representation of incoming request
    ///
    /// @return responseMessage
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleInitializeRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialized request
    ///
    /// @param string representation of incoming request
    ///
    /// @return responseMessage
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleInitializedRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didOpen request
    ///
    /// @param string representation of incoming request
    ///
    /// @return responseMessage
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleTextDocumentDidOpenRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didChange request
    ///
    /// @param string representation of incoming request
    ///
    /// @return responseMessage
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleTextDocumentDidChangeRequest(const std::string &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/hover request
    ///
    /// @param string representation of incoming request
    ///
    /// @return responseMessage
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage handleTextDocumentHoverRequest(const std::string &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Request counter
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPCounter> m_justAnLspCounters = std::unique_ptr<JustAnLSPCounter>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Track only one client for the start
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<JustAnLSPClient> m_justAnLSPClient;
};

} // namespace justanlsp
