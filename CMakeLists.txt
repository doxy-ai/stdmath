CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(stdmath CXX)

set(CMAKE_CXX_STANDARD 26)

include(CheckIncludeFiles)
check_include_files("<linalg>" STDMATH_HAS_LINALG)
if(NOT STDMATH_HAS_LINALG)
    message("std::linalg not found, fetching from github")
    include(cmake/stdBLAS.cmake)
endif()

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE std::linalg)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
if(NOT STDMATH_HAS_LINALG)
    target_include_directories(${PROJECT_NAME} INTERFACE ${stdblas_SOURCE_DIR}/include/experimental/)
endif()

add_library(std::math ALIAS ${PROJECT_NAME})