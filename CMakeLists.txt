cmake_minimum_required(VERSION 3.15)
project(JustAnLSPServerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/capabilities)
include_directories(${SRC_DIR}/core)
include_directories(${SRC_DIR}/enums)
include_directories(${SRC_DIR}/errors)
include_directories(${SRC_DIR}/factories)
include_directories(${SRC_DIR}/messages)
include_directories(${SRC_DIR}/params)
include_directories(${SRC_DIR}/rpc)
include_directories(${SRC_DIR}/types)
include_directories(${SRC_DIR}/utils)

file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.h
)

add_executable(JustAnLSPServer ${SOURCES})

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5
)

FetchContent_MakeAvailable(nlohmann_json)
target_link_libraries(JustAnLSPServer PRIVATE nlohmann_json::nlohmann_json)

