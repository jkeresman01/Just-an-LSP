#pragma once

#include "InitializeParams.h"

namespace justanlsp
{
InitializeParams::InitializeParams(const nlohmann::json &jsonRPC)
    : m_processId(jsonRPC["proccessId"]), m_locale(jsonRPC["locale"])
{
    nlohmann::json clientInfoJson = jsonRPC["clientInfo"];

    m_clientInfo.name = clientInfoJson["name"];
    m_clientInfo.version = clientInfoJson["version"];
}
} // namespace justanlsp
