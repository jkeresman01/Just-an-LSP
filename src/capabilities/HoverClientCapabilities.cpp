#include "HoverClientCapabilities.h"

namespace justanlsp
{

HoverClientCapabilities::HoverClientCapabilities(const nlohmann::json &jsonRPC)
{
    m_contentFormats.reserve(size_t(MarkupKind::MAX_NUMBER_OF_OPTIONS));

    // TODO get contentForrmat from request and dynamic reg options
}

} // namespace justanlsp
