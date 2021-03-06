cmake_minimum_required(VERSION 3.5)

project(botctl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include("${CMAKE_SOURCE_DIR}/third_party/rapid_json.cmake")
# Add source files
# file(GLOB_RECURSE SRC_CC "src/*.cc")

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    ${GFLAGS_INCLUDE_DIR}
    ${BENCHMARK_INCLUDE_DIR}
    ${RAPIDJSON_INCLUDE_DIR}
)

add_subdirectory("botctl/bot/types")
add_subdirectory("botctl/bot/types/types-test")

add_executable(cbot main.cpp)
target_link_libraries(cbot gflags pthread ${SRC_CC})
add_dependencies(cbot rapidjson)
