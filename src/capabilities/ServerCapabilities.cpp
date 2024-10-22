#include "ServerCapabilities.h"

namespace justanlsp
{
nlohmann::json ServerCapabilities::toJson() const
{
    nlohmann::json serverCapabilitiesJson = {{"textDocumentSync", m_textDocumentSyncKind}};

    return serverCapabilitiesJson;
}
} // namespace justanlsp
