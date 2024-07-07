cmake_minimum_required(VERSION 3.10)
project(Just-an-LSP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.5
)

FetchContent_MakeAvailable(nlohmann_json)

include_directories(${PROJECT_SOURCE_DIR}/source)

set(SOURCES
    source/Main.cpp
    source/LanguageServer.cpp
)

add_executable(Just-an-LSP ${SOURCES})

target_link_libraries(Just-an-LSP PRIVATE nlohmann_json::nlohmann_json)

