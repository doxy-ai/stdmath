
cmake_minimum_required(VERSION 3.30)
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a") #this require to enable c++ module feature in my cmake version
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1) # enable scan dependencies /scanDependencies
project(stdmath CXX)

set(CMAKE_CXX_STANDARD 26)
include(cmake/c++20modules.cmake)

option(STDMATH_BUILD_TESTS "Should we build the unit tests?" ${PROJECT_IS_TOP_LEVEL})

add_library(stdmath)
target_sources(stdmath PUBLIC
	FILE_SET stdmath TYPE CXX_MODULES
	# BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
	FILES 
		util/simd_emulation.cppm
		util/types.cppm
		math/vector.cppm
)
target_include_directories(stdmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_library(std::math ALIAS stdmath)

if(STDMATH_BUILD_TESTS)
	add_subdirectory(tests)
endif()
