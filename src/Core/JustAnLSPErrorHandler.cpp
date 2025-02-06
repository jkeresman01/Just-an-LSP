#include "JustAnLSPErrorHandler.h"

#include "../Messages/Response/ResponseMessage.h"
#include "../Rpc/Rpc.h"
#include "../Utils/Logger.h"
#include "JustAnLSPErrorDirector.h"

namespace justanlsp
{

void JustAnLSPErrorHandler::handleServerNotInitalizedError(int64_t id)
{
    JLSP_DEBUG("Handling server not initialized error");

    ResponseError::Builder errorBuilder;
    JustAnLSPErrorDirector::buildServerNotInitializedError(errorBuilder);
    ResponseError serverNotInitializedError = errorBuilder.build();

    handleError(serverNotInitializedError, id);
}

void JustAnLSPErrorHandler::handleParseError(int64_t id)
{
    JLSP_DEBUG("Handling parse error");

    ResponseError::Builder errorBuilder;
    JustAnLSPErrorDirector::buildParseError(errorBuilder);
    ResponseError parseError = errorBuilder.build();

    handleError(parseError, id);
}

void JustAnLSPErrorHandler::handleMethodNotFoundError(int64_t id)
{
    JLSP_DEBUG("Handling method not found error");

    ResponseError::Builder errorBuilder;
    JustAnLSPErrorDirector::buildMethodNotFoundError(errorBuilder);
    ResponseError methodNotFoundError = errorBuilder.build();

    handleError(methodNotFoundError, id);
}

void JustAnLSPErrorHandler::handleInternalError(int64_t id)
{
    JLSP_DEBUG("Handling internal server error");

    ResponseError::Builder errorBuilder;
    JustAnLSPErrorDirector::buildInternalServerError(errorBuilder);
    ResponseError internalServerError = errorBuilder.build();

    handleError(internalServerError, id);
}

void JustAnLSPErrorHandler::handleReceivedReqAfterShutdownError(int64_t id)
{
    JLSP_DEBUG("Handling invalid request error");

    ResponseError::Builder errorBuilder;
    JustAnLSPErrorDirector::buildInternalServerError(errorBuilder);
    ResponseError invalidRequestError = errorBuilder.build();

    handleError(invalidRequestError, id);
}

void JustAnLSPErrorHandler::handleError(const ResponseError &responseError, int64_t id)
{
    JLSP_DEBUG(STR("Sending response error: %s", responseError.toString().c_str()));

    ResponseMessage responseMessage("2.0", id, responseError);

    Rpc::send(responseMessage);
}

} // namespace justanlsp
