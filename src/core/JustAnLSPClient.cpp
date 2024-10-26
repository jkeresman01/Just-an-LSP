#include "JustAnLSPClient.h"

#include <memory>

#include "../utils/Logger.h"

namespace justanlsp
{

JustAnLSPClient::JustAnLSPClient(const ClientInfo &clientInfo,
                                 const std::shared_ptr<ClientCapabilities> &clientCapabilites)
{
    saveInfo(clientInfo);
    registerCapabilites(clientCapabilites);
}

void JustAnLSPClient::saveInfo(const ClientInfo &clientInfo)
{
    m_clientInfo = clientInfo;
}

void JustAnLSPClient::registerCapabilites(const std::shared_ptr<ClientCapabilities> &clientCapabilites)
{
    m_clientCapabilities = clientCapabilites;
}

void JustAnLSPClient::addDocument(const std::string &URI, const std::string &document)
{
    m_documentState.emplace(URI, document);
}

std::string JustAnLSPClient::getDocumentByURI(const std::string &URI) const
{
    auto it = m_documentState.find(URI);

    if (it == m_documentState.end())
    {
        LOG_ERROR << "There are no registered documents with URI: " << URI << "!";
    }

    return it->second;
}

void JustAnLSPClient::updateDocumentByURI(const std::string &URI, const std::string &document)
{
    m_clientCapabilities.getTextDocumentCapabilites().;
    m_documentState[URI] = document;
}

} // namespace justanlsp
