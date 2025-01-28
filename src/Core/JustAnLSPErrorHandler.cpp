#include "JustAnLSPErrorHandler.h"

#include "../Messages/Response/ResponseMessage.h"
#include "../Rpc/Rpc.h"
#include "../Utils/Logger.h"

namespace justanlsp
{

void JustAnLSPErrorHandler::handleServerNotInitalizedError(int64_t id)
{
    JLSP_DEBUG("Handling server not initialized error");

    ResponseError serverNotInitializedError =
        ResponseError::Builder()
            .withErrorCode(ErrorCodes::SERVER_NOT_INITIALIZED)
            .withErrorMessage("Received request before initiliazition request was send!")
            .build();

    handleError(serverNotInitializedError, id);
}

void JustAnLSPErrorHandler::handleParseError(int64_t id)
{
    JLSP_DEBUG("Handling parse error");

    ResponseError parseError = ResponseError::Builder()
                                   .withErrorCode(ErrorCodes::PARSE_ERROR)
                                   .withErrorMessage("Parsing error happened, while processing request!")
                                   .build();

    handleError(parseError, id);
}

void JustAnLSPErrorHandler::handleMethodNotFoundError(int64_t id)
{
    JLSP_DEBUG("Handling method not found error");

    ResponseError methodNotFoundError = ResponseError::Builder()
                                            .withErrorCode(ErrorCodes::METHOD_NOT_FOUND)
                                            .withErrorMessage("Didn't find method for given request")
                                            .build();

    handleError(methodNotFoundError, id);
}

void JustAnLSPErrorHandler::handleInternalError(int64_t id)
{
    JLSP_DEBUG("Handling internal server error");

    ResponseError internalServerError = ResponseError::Builder()
                                            .withErrorCode(ErrorCodes::INTERNAL_ERROR)
                                            .withErrorMessage("Internal error happened")
                                            .build();

    handleError(internalServerError, id);
}

void JustAnLSPErrorHandler::handleReceivedReqAfterShutdownError(int64_t id)
{
    JLSP_DEBUG("Handling invalid request error");

    ResponseError invalidRequestError = ResponseError::Builder()
                                            .withErrorCode(ErrorCodes::INVALID_REQUEST)
                                            .withErrorMessage("Received request after shutdown")
                                            .build();

    handleError(invalidRequestError, id);
}

void JustAnLSPErrorHandler::handleError(const ResponseError &responseError, int64_t id)
{
    JLSP_DEBUG(STR("Sending response error: %s", responseError.toString().c_str()));

    ResponseMessage responseMessage("2.0", id, responseError);

    Rpc::send(responseMessage);
}

} // namespace justanlsp
