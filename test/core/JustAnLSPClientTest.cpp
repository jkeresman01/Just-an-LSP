#include <gtest/gtest.h>

#include "../../src/capabilities/ClientCapabilites.h"
#include "../../src/core/JustAnLSPClient.h"
#include "../../src/types/ClientInfo.h"

#include <memory>

namespace justanlsp
{
class JustAnLSPClientTest : public ::testing::Test
{
  protected:
    ClientInfo mockClientInfo{"TestClient", "1"};
    std::shared_ptr<ClientCapabilities> mockCapabilities = std::make_shared<ClientCapabilities>();
    JustAnLSPClient client{mockClientInfo, mockCapabilities};
};

TEST_F(JustAnLSPClientTest, WillSaveClientInfoCorrectly)
{
    // GIVEN
    ClientInfo newClientInfo{"NewClient", "2"};

    // WHEN
    client.saveInfo(newClientInfo);

    // THEN
    EXPECT_EQ(client.getInfo(), newClientInfo.toString());
}

TEST_F(JustAnLSPClientTest, WillAddDocumentCorrectly)
{
    // GIVEN
    std::string URI = "document1";
    std::string documentContent = "Ahaahaha tada tatarata";

    // WHEN
    client.addDocument(URI, documentContent);

    // THEN
    EXPECT_EQ(client.getDocumentByURI(URI), documentContent);
}

TEST_F(JustAnLSPClientTest, WillLogErrorForUnknownURI)
{
    // GIVEN
    std::string unknownURI = "Kolinda";

    // WHEN
    std::string result = client.getDocumentByURI(unknownURI);

    // THEN
    EXPECT_EQ(result, "");
}

TEST_F(JustAnLSPClientTest, WillUpdateDocumentCorrectly)
{
    // GIVEN
    std::string URI = "document1";
    std::string initialContent = "Initial content";
    client.addDocument(URI, initialContent);

    // WHEN
    std::string updatedContent = "Updated content";
    client.updateDocumentWithURI(URI, updatedContent);

    // THEN
    EXPECT_EQ(client.getDocumentByURI(URI), updatedContent);
}

} // namespace justanlsp
