#include "JustAnLSPFacade.h"

#include "RequestType.h"
#include "RequestUtil.h"

namespace justanlsp
{

ResponseMessage JustAnLSPFacade::handleRequest(const std::string &request)
{

    switch (RequestUtil::getRequestType(request))
    {
    case RequestType::INITIALIZE:
        handleInitializeRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_OPEN:
        handleTextDocumentDidOpenRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_CHANGE:
        handleTextDocumentDidChangeRequest(request);
        break;
    default:
        /* LOG_ERROR("Received unkown request: " <<  msgTypeToString(messageType) << "!") */
        break;
    }
}

} // namespace justanlsp
