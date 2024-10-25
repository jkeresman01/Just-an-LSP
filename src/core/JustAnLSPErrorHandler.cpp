#include "JustAnLSPErrorHandler.h"

#include "../messages/ResponseMessage.h"
#include "../rpc/Rpc.h"
#include "../utils/Logger.h"

namespace justanlsp
{

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

    ResponseError parseError{ErrorCodes::PARSE_ERROR,
                             "There was an parse error during processing of request!"};

    ResponseMessage parseErrorResponse =
        ResponseMessage::Builder().withJsonRPC("2.0").withResponseError(parseError).build();

    Rpc::send(parseErrorResponse);
}

void JustAnLSPErrorHandler::handleMethodNotFoundError()
{
    LOG_INFO << "Handling method not found error";

    ResponseError methodNotFoundError{ErrorCodes::METHOD_NOT_FOUND, "Didn't find method for given request"};

    ResponseMessage methodNotFoundResponse =
        ResponseMessage::Builder().withJsonRPC("2.0").withResponseError(methodNotFoundError).build();

    Rpc::send(methodNotFoundResponse);
}

void JustAnLSPErrorHandler::handleInternalError()
{
    LOG_INFO << "Handling internal error";

    ResponseError internalError{ErrorCodes::INTERNAL_ERROR, "Internal error happened"};

    ResponseMessage internalErrorResponse =
        ResponseMessage::Builder().withJsonRPC("2.0").withResponseError(internalError).build();

    Rpc::send(internalErrorResponse);
}

} // namespace justanlsp
