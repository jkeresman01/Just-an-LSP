cmake_minimum_required(VERSION 3.10)
project(JustAnLSPTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/../src)
include_directories(${CMAKE_SOURCE_DIR}/../src/algo)
include_directories(${CMAKE_SOURCE_DIR}/../src/capabilities)
include_directories(${CMAKE_SOURCE_DIR}/../src/core)
include_directories(${CMAKE_SOURCE_DIR}/../src/enums)
include_directories(${CMAKE_SOURCE_DIR}/../src/errors)
include_directories(${CMAKE_SOURCE_DIR}/../src/factories)
include_directories(${CMAKE_SOURCE_DIR}/../src/messages)
include_directories(${CMAKE_SOURCE_DIR}/../src/params)
include_directories(${CMAKE_SOURCE_DIR}/../src/rpc)
include_directories(${CMAKE_SOURCE_DIR}/../src/types)
include_directories(${CMAKE_SOURCE_DIR}/../src/utils)

set(SOURCE_FILES
    ../src/algo/Trie.cpp 
)

set(TEST_FILES
    Test.cpp
    algo/TrieTest.cpp 
    utils/ConvertTest.cpp 
    utils/RequestMethodType.cpp
    utils/TraceLevelTest.cpp
)

add_executable(run-tests ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(run-tests ${GTEST_LIBRARIES} pthread)

