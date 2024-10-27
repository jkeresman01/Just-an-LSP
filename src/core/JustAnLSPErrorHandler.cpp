#include "JustAnLSPErrorHandler.h"

#include "../messages/ResponseMessage.h"
#include "../rpc/Rpc.h"
#include "../utils/Logger.h"

namespace justanlsp
{

void JustAnLSPErrorHandler::handleServerNotInitalizedError(int64_t id)
{
    LOG_INFO << "Handling server not initialized error";

    ResponseError serverNotInitializedError{ErrorCodes::SERVER_NOT_INITIALIZED,
                                            "Received request before initialization"};

    handleError(serverNotInitializedError, id);
}

void JustAnLSPErrorHandler::handleParseError(int64_t id)
{
    LOG_INFO << "Handling parse error";

    ResponseError parseError{ErrorCodes::PARSE_ERROR,
                             "There was an parse error during processing of request!"};

    handleError(parseError, id);
}

void JustAnLSPErrorHandler::handleMethodNotFoundError(int64_t id)
{
    LOG_INFO << "Handling method not found error";

    ResponseError methodNotFoundError{ErrorCodes::METHOD_NOT_FOUND, "Didn't find method for given request"};

    handleError(methodNotFoundError, id);
}

void JustAnLSPErrorHandler::handleInternalError(int64_t id)
{
    LOG_INFO << "Handling internal server error";

    ResponseError internalServerError{ErrorCodes::INTERNAL_ERROR, "Internal error happened"};

    handleError(internalServerError, id);
}

void JustAnLSPErrorHandler::handleReceivedReqAfterShutdownError(int64_t id)
{
    LOG_INFO << "Handling invalid request error";

    ResponseError invalidRequestError{ErrorCodes::INVALID_REQUEST, "Received request after shutdown"};

    handleError(invalidRequestError, id);
}

void JustAnLSPErrorHandler::handleError(const ResponseError &responseError, int64_t id)
{
    LOG_INFO << "Sending response error: " << responseError.toString();

    ResponseMessage responseMessage("2.0", id, responseError);

    Rpc::send(responseMessage);
}

} // namespace justanlsp
