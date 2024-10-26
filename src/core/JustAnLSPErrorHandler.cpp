#include "JustAnLSPErrorHandler.h"

#include "../messages/ResponseMessage.h"
#include "../rpc/Rpc.h"
#include "../utils/Logger.h"

namespace justanlsp
{

void JustAnLSPErrorHandler::handleServerNotInitalizedError()
{
    LOG_INFO << "Handling server not initialized error";

    handleError({ErrorCodes::SERVER_NOT_INITIALIZED, "Received request before initialization"});
}

void JustAnLSPErrorHandler::handleParseError()
{
    LOG_INFO << "Handling parse error";

    handleError({ErrorCodes::PARSE_ERROR, "There was an parse error during processing of request!"});
}

void JustAnLSPErrorHandler::handleMethodNotFoundError()
{
    LOG_INFO << "Handling method not found error";

    handleError({ErrorCodes::METHOD_NOT_FOUND, "Didn't find method for given request"});
}

void JustAnLSPErrorHandler::handleInternalError()
{
    LOG_INFO << "Handling internal error";

    handleError({ErrorCodes::INTERNAL_ERROR, "Internal error happened"});
}

void JustAnLSPErrorHandler::handleError(const ResponseError &responseError)
{
    LOG_INFO << "Sending response error: " << responseError.toString();

    /* ResponseMessage responseErrorMsg = */
    /*     ResponseMessage::Builder().withJsonRPC("2.0").withResponseError(responseError).build(); */

    /* Rpc::send(responseErrorMsg); */
}

} // namespace justanlsp
