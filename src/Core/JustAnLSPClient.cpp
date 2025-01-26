#include "JustAnLSPClient.h"

#include <memory>

#include "../Utils/Logger.h"

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
    m_documentsByURI.emplace(URI, document);

    JLSP_INFO(STR("Added text document with URI: %s, for client: %s", URI.c_str(),
                  m_clientInfo.toString().c_str()));
}

std::string JustAnLSPClient::getDocumentByURI(const std::string &URI) const
{
    auto it = m_documentsByURI.find(URI);

    if (it == m_documentsByURI.end())
    {
        JLSP_ERROR(STR("There are no registered documents with URI: %s !", URI.c_str()));
        return std::string();
    }

    return it->second;
}

void JustAnLSPClient::updateDocumentWithURI(const std::string &URI, const std::string &document)
{
    m_documentsByURI[URI] = document;

    JLSP_INFO(STR("Updated text document with URI: %s, for client: %s", URI.c_str(),
                  m_clientInfo.toString().c_str()));
}

} // namespace justanlsp
