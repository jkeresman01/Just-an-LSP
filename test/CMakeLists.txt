cmake_minimum_required(VERSION 3.10)
project(JustAnLSPTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(nlohmann_json)

include_directories(
    ${CMAKE_SOURCE_DIR}/../src
    ${CMAKE_SOURCE_DIR}/../src/algo
    ${CMAKE_SOURCE_DIR}/../src/capabilities
    ${CMAKE_SOURCE_DIR}/../src/core
    ${CMAKE_SOURCE_DIR}/../src/enums
    ${CMAKE_SOURCE_DIR}/../src/errors
    ${CMAKE_SOURCE_DIR}/../src/factories
    ${CMAKE_SOURCE_DIR}/../src/messages
    ${CMAKE_SOURCE_DIR}/../src/params
    ${CMAKE_SOURCE_DIR}/../src/rpc
    ${CMAKE_SOURCE_DIR}/../src/types
    ${CMAKE_SOURCE_DIR}/../src/utils
)

set(SOURCE_FILES
    ../src/algo/Trie.cpp 
    ../src/core/JustAnLSPCounter.cpp
    ../src/messages/response/CompletionResponse.cpp
    ../src/messages/response/InitializeResponse.cpp
    ../src/messages/response/ResponseMessage.cpp
    ../src/results/CompletionResult.cpp
    ../src/results/InitializeResult.cpp
    ../src/capabilities/ServerCapabilities.cpp
    ../src/messages/response/ResponseError.cpp
)

set(TEST_FILES
    Test.cpp
    algo/TrieTest.cpp 
    core/JustAnLSPCounterTest.cpp 
    rpc/RpcTest.cpp 
    messages/ResponseMessageTest.cpp
    messages/CompletionResponseTest.cpp
    messages/InitializeResponseTest.cpp
    messages/ShutdownResponseTest.cpp
    utils/ConvertTest.cpp 
    utils/RequestMethodType.cpp
    utils/MessageUtilTest.cpp
    utils/TraceLevelTest.cpp
)

add_executable(run-tests ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(run-tests PRIVATE ${GTEST_LIBRARIES} pthread nlohmann_json::nlohmann_json)

