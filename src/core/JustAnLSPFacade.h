#pragma onceFaca

#include <memory>
#include <string>

#include "../messages/ResponseMessage.h"
#include "JustAnLSPClient.h"

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
    /// @brief Default constructor
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPFacade() = default;

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
    /// @brief Registered client (editor or tool)
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<JustAnLSPClient> m_client = std::make_shared<JustAnLSPClient>();
};

} // namespace justanlsp
