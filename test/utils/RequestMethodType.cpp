#include <gtest/gtest.h>

#include "../../src/enums/RequestType.h"
#include "../../src/utils/RequestMethodUtil.h"

using namespace justanlsp;

class RequestMethodUtilTest : public ::testing::Test
{
};

TEST_F(RequestMethodUtilTest, WillReturnInitializeType)
{
    // GIVEN
    std::string method = "initialize";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::INITIALIZE);
}

TEST_F(RequestMethodUtilTest, WillReturnInitializedType)
{
    // GIVEN
    std::string method = "initialized";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::INITIALIZED);
}

TEST_F(RequestMethodUtilTest, WillReturnTextDocumentDidChangeType)
{
    // GIVEN
    std::string method = "textDocument/didChange";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::TEXT_DOCUMENT_DID_CHANGE);
}

TEST_F(RequestMethodUtilTest, WillReturnTextDocumentCompletionType)
{
    // GIVEN
    std::string method = "textDocument/completion";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::TEXT_DOCUMENT_COMPLETION);
}

TEST_F(RequestMethodUtilTest, WillReturnTextDocumentDidOpenType)
{
    // GIVEN
    std::string method = "textDocument/didOpen";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::TEXT_DOCUMENT_DID_OPEN);
}

TEST_F(RequestMethodUtilTest, WillReturnTextDocumentHoverType)
{
    // GIVEN
    std::string method = "textDocument/hover";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::TEXT_DOCUMENT_HOVER);
}

TEST_F(RequestMethodUtilTest, WillReturnShutdownType)
{
    // GIVEN
    std::string method = "shutdown";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::SHUTDOWN);
}

TEST_F(RequestMethodUtilTest, WillReturnExitType)
{
    // GIVEN
    std::string method = "exit";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::EXIT);
}

TEST_F(RequestMethodUtilTest, WillReturnUnknownTypeForInvalidMethod)
{
    // GIVEN
    std::string method = "unknownMethod";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::UNKNOWN);
}

TEST_F(RequestMethodUtilTest, WillReturnUnknownTypeForEmptyMethod)
{
    // GIVEN
    std::string method = "";

    // WHEN
    RequestType result = RequestMethodUtil::getType(method);

    // THEN
    EXPECT_EQ(result, RequestType::UNKNOWN);
}
