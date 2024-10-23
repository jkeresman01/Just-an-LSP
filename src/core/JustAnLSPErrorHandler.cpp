#include "JustAnLSPErrorHandler.h"

#include "../messages/ResponseMessage.h"
#include "../rpc/Rpc.h"
#include "../utils/Logger.h"

namespace justanlsp
{
void JustAnLSPErrorHandler::handle(const ErrorCodes errorCode)
{
    switch (errorCode)
    {
    case ErrorCodes::SERVER_NOT_INITIALIZED:
        handleServerNotInitalizedError();
        break;
    case ErrorCodes::PARSE_ERROR:
        break;
    case ErrorCodes::METHOD_NOT_FOUND:
        break;
    case ErrorCodes::INTERNAL_ERROR:
        break;
    default:
        LOG_WARN << "Wrong error code";
    }
}

void JustAnLSPErrorHandler::handleServerNotInitalizedError()
{
    LOG_INFO << "Handling server not initialized error";

    ResponseError serverNotInitialized{ErrorCodes::SERVER_NOT_INITIALIZED,
                                       "Received reqeuest before initialization"};

    ResponseMessage initializationFailureResponse =
        ResponseMessage::Builder().withJsonRPC("2.0").withResponseError(serverNotInitialized).build();

    Rpc::send(initializationFailureResponse);
}

void JustAnLSPErrorHandler::handleParseError()
{
    LOG_INFO << "Handling server not initialized error";
}

void JustAnLSPErrorHandler::handleMethodNotFoundError()
{
    LOG_INFO << "Handling server not initialized error";
}

void JustAnLSPErrorHandler::handleInternalError()
{
    LOG_INFO << "Handling server not initialized error";
}

} // namespace justanlsp
