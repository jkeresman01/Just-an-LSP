#pragma once

#include "ServerCapabilities.h"

namespace justanlsp
{
class ServerCapabilitiesDirector
{
  public:
    ServerCapabilitiesDirector() = delete;

    static ServerCapabilities getDefaultServerCapabilites(
        ServerCapabilities::Builder &serverCapabilitesBuilder)
    {
        serverCapabilitesBuilder.withTextDocumentSyncKind(TextDocumentSyncKind::FULL);
        serverCapabilitesBuilder.withHoverSupport(true);
        serverCapabilitesBuilder.withSnippetSupport(true);
        serverCapabilitesBuilder.withCompletionSupport(true);
        serverCapabilitesBuilder.withCodeActionSupport(true);
        return serverCapabilitesBuilder.build();
    }
};
} // namespace justanlsp
