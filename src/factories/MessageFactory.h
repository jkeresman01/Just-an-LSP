#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../messages/InitializeRequest.h"
#include "../messages/ShutdownRequest.h"
#include "../utils/Logger.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class MessageFactory
///
/// @brief Factory class to create instances of various LSP request
///        message objects.
///
//////////////////////////////////////////////////////////////
class MessageFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    MessageFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an InitializeRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an InitializeRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<InitializeRequest> createInitializeReq(const nlohmann::json &jsonRPC)
    {
        LOG_INFO << "Creating initalize requst in factory impl!";
        return std::make_shared<InitializeRequest>(jsonRPC);
    }

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a ShutdownRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a ShutdownRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createShutdownReq(const nlohmann::json &jsonRPC) */
    /*     { */
    /*         return std::make_shared<ShutdownRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a DidOpenTextDocumentRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a DidOpenTextDocumentRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createDidOpenTextDocumentReq(const nlohmann::json &jsonRPC)
     */
    /*     { */
    /*         return std::make_shared<DidOpenTextDocumentRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a DidCloseTextDocumentRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a DidCloseTextDocumentRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createDidCloseTextDocumentReq(const nlohmann::json &jsonRPC)
     */
    /*     { */
    /*         return std::make_shared<DidCloseTextDocumentRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a DidChangeTextDocumentRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a DidChangeTextDocumentRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createDidChangeTextDocumentReq(const nlohmann::json
     * &jsonRPC) */
    /*     { */
    /*         return std::make_shared<DidChangeTextDocumentRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a DidSaveTextDocumentRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a DidSaveTextDocumentRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createDidSaveTextDocumentReq(const nlohmann::json &jsonRPC)
     */
    /*     { */
    /*         return std::make_shared<DidSaveTextDocumentRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a CompletionRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a CompletionRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createCompletionReq(const nlohmann::json &jsonRPC) */
    /*     { */
    /*         return std::make_shared<CompletionRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a DefinitionRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a DefinitionRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createDefinitionReq(const nlohmann::json &jsonRPC) */
    /*     { */
    /*         return std::make_shared<DefinitionRequest>(jsonRPC); */
    /*     } */

    /*     ////////////////////////////////////////////////////////////// */
    /*     /// */
    /*     /// @brief Creates a ReferencesRequest message object. */
    /*     /// */
    /*     /// @param jsonRPC The JSON object containing the request data. */
    /*     /// */
    /*     /// @return A shared pointer to a ReferencesRequest object. */
    /*     /// */
    /*     ////////////////////////////////////////////////////////////// */
    /*     static std::shared_ptr<RequestMessage> createReferencesReq(const nlohmann::json &jsonRPC) */
    /*     { */
    /*         return std::make_shared<ReferencesRequest>(jsonRPC); */
    /*     } */
};

} // namespace justanlsp
