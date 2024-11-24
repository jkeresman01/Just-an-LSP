#pragma once

#include "ResponseError.h"

namespace justanlsp
{
    class ResponseErrorDirector
    {
        public:
            static ResponseError getServerNotInitializedResponseError(ResponseError::Builder& builder)
            {
                builder.withErrorCode(ErrorCodes::SERVER_NOT_INITIALIZED); 
                builder.withErrorMessage("Received request before initialization");
                return builder.build();
            }
            
            static ResponseError getParseResponseError(ResponseError::Builder& builder)
            {
                builder.withErrorCode(ErrorCodes::PARSE_ERROR); 
                builder.withErrorMessage("There was an parse error during processing of request!");
                return builder.build();
            }

            static ResponseError getInterServerResponseErro(ResponseError::Builder& builder)
            {
                builder.withErrorCode(ErrorCodes::METHOD_NOT_FOUND); 
                builder.withErrorMessage("Didn't find method for given request");
                return builder.build();
            }

            static ResponseError getRequestReceivedAfterShutdownResponseError(ResponseError::Builder& builder)
            {
                builder.withErrorCode(ErrorCodes::INVALID_REQUEST); 
                builder.withErrorMessage("Received request after shutdown");
                return builder.build();
            }

    };
}
