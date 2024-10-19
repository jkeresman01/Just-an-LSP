#pragma once

namespace justanlsp
{

enum class RequestType
{
    INITIALIZE,
    TEXT_DOCUMENT_DID_OPEN,
    TEXT_DOCUMENT_DID_CHANGE,
    UNKNOWN,
};

}
