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
        return handleInitializeRequest(request);
    case RequestType::TEXT_DOCUMENT_DID_OPEN:
        return handleTextDocumentDidOpenRequest(request);
    case RequestType::TEXT_DOCUMENT_DID_CHANGE:
        return handleTextDocumentDidChangeRequest(request);
    default:
        LOG_WARN("Received request of unkown type");
        break;
    }
}

ResponseMessage JustAnLSPFacade::handleInitializeRequest(const std::string &request) {}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidOpenRequest(const std::string &request) {}

ResponseMessage JustAnLSPFacade::handleTextDocumentDidChangeRequest(const std::string &request) {}

} // namespace justanlsp
