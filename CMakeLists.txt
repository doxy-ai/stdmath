CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(stdmath CXX)

set(CMAKE_CXX_STANDARD 26)

option(STDMATH_BUILD_TESTS "Should we build the unit tests?" ${PROJECT_IS_TOP_LEVEL})

add_library(stdmath INTERFACE)
target_include_directories(stdmath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(std::math ALIAS stdmath)

if(STDMATH_BUILD_TESTS)
    add_subdirectory(tests)
endif()