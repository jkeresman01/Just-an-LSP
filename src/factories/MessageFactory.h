#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../messages/DidChangeTextDocumentRequest.h"
#include "../messages/DidOpenTextDocumentRequest.h"
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
        return std::make_shared<InitializeRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an ShutdownRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an ShutdownRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ShutdownRequest> createShutdownReq(const nlohmann::json &jsonRPC)
    {
        return std::make_unique<ShutdownRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an DidOpenTextDocumentRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an DidOpenTextDocumentRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<DidOpenTextDocumentRequest> createDidOpenTextDocumentReq(
        const nlohmann::json &jsonRPC)
    {
        return std::make_unique<DidOpenTextDocumentRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    ///
    /// @brief Creates an DidChangeTextDocument message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an DidChangeTextDocument object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<DidChangeTextDocumentRequest> createDidChangeTextDocumentReq(
        const nlohmann::json &jsonRPC)
    {
        return std::make_unique<DidChangeTextDocumentRequest>(jsonRPC);
    }
};

} // namespace justanlsp
