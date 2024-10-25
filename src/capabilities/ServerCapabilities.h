#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../enums/TextDocumentSyncKind.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilities
///
/// @brief ServerCapabilities ...
///
//////////////////////////////////////////////////////////////
class ServerCapabilities
{
    // TODO rest of the capilites (only text is provided for now)

  public:
    ServerCapabilities() = default;
    ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind);

    nlohmann::json toJson() const;

  private:
    TextDocumentSyncKind m_textDocumentSyncKind;
};
} // namespace justanlsp
