# Modified from: https://github.com/stripe2933/CppStandardLibraryModule

cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

# Check compiler support for C++23 Standard Library Module.
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "17.0.0")
	if (CMAKE_CXX_STANDARD LESS 20)
		message(FATAL_ERROR "C++20 or newer is required.")
	endif()

	set(CACHE CLANG_STANDARD_MODULE_PATH TYPE FILEPATH HELP "Path to where the clang std and std.compat modules are located" /usr/share/libc++/v1)
	message("path = ${CLANG_STANDARD_MODULE_PATH}")

	# add_custom_target(
	# 	std_module
	# 	COMMAND ${CMAKE_CXX_COMPILER} -std=gnu++2c -stdlib=libc++ --precompile -o ${CMAKE_BINARY_DIR}/std.pcm ${CLANG_STANDARD_MODULE_PATH}/std.cppm
	# 	BYPRODUCTS ${CMAKE_BINARY_DIR}/std.pcm
	# )
	# add_custom_target(
	# 	std_compat_module
	# 	DEPENDS std_module
	# 	COMMAND ${CMAKE_CXX_COMPILER} -std=gnu++2c -stdlib=libc++ --precompile -fmodule-file=std=${CMAKE_BINARY_DIR}/std.pcm -o ${CMAKE_BINARY_DIR}/std.compat.pcm ${CLANG_STANDARD_MODULE_PATH}/std.compat.cppm
	# 	BYPRODUCTS ${CMAKE_BINARY_DIR}/std.compat.pcm
	# )
	add_custom_command(
		OUTPUT ${CMAKE_BINARY_DIR}/std.pcm
		COMMAND ${CMAKE_CXX_COMPILER}
				-std=gnu++2c # TODO: How do we link this to CXX_STANDARD?
				-stdlib=libc++
				--precompile
				-o ${CMAKE_BINARY_DIR}/std.pcm
				${CLANG_STANDARD_MODULE_PATH}/std.cppm
		DEPENDS ${CLANG_STANDARD_MODULE_PATH}/std.cppm
		COMMENT "Precompiling std module"
	)

	add_custom_target(
		std_module
		DEPENDS ${CMAKE_BINARY_DIR}/std.pcm
	)

	add_custom_command(
		OUTPUT ${CMAKE_BINARY_DIR}/std.compat.pcm
		COMMAND ${CMAKE_CXX_COMPILER}
				-std=gnu++2c
				-stdlib=libc++
				--precompile
				-fmodule-file=std=${CMAKE_BINARY_DIR}/std.pcm
				-o ${CMAKE_BINARY_DIR}/std.compat.pcm
				${CLANG_STANDARD_MODULE_PATH}/std.compat.cppm
		DEPENDS
			${CMAKE_BINARY_DIR}/std.pcm
			${CLANG_STANDARD_MODULE_PATH}/std.compat.cppm
		COMMENT "Precompiling std.compat module"
	)

	add_custom_target(
		std_compat_module
		DEPENDS ${CMAKE_BINARY_DIR}/std.compat.pcm
	)

	add_library(std INTERFACE) 
	# target_sources(std PUBLIC
	# 	FILE_SET CXX_MODULES
	# 	BASE_DIRS ${CLANG_STANDARD_MODULE_PATH}
	# 	FILES
	# 		${CLANG_STANDARD_MODULE_PATH}/std.cppm
	# 		${CLANG_STANDARD_MODULE_PATH}/std.compat.cppm
	# )
	target_compile_options(std INTERFACE -stdlib=libc++ -fmodule-file=std=${CMAKE_BINARY_DIR}/std.pcm -fmodule-file=std.compat=${CMAKE_BINARY_DIR}/std.compat.pcm)
	target_link_options(std INTERFACE -stdlib=libc++ -fmodule-file=std=${CMAKE_BINARY_DIR}/std.pcm -fmodule-file=std.compat=${CMAKE_BINARY_DIR}/std.compat.pcm)
	add_dependencies(std std_module std_compat_module)

	link_libraries(std)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "19.36")
	if (CMAKE_CXX_STANDARD VERSION_LESS 20)
		message(FATAL_ERROR "C++20 or newer is required.")
	elseif (CMAKE_CXX_STANDARD VERSION_LESS 23 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.38")
		message(FATAL_ERROR "C++23 Standard library module in C++20 is only supported with MSVC 19.38 or newer.")
	endif()

	file(TO_CMAKE_PATH "${VCTOOLS_INSTALL_DIR}" VCTOOLS_INSTALL_DIR)

	add_library(std)
	target_sources(std PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS ${VCTOOLS_INSTALL_DIR}/modules
		FILES
			${VCTOOLS_INSTALL_DIR}/modules/std.ixx
			${VCTOOLS_INSTALL_DIR}/modules/std.compat.ixx
	)

	link_libraries(std)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	execute_process(
		COMMAND bash -c "${CMAKE_CXX_COMPILER} -E -Wp,-v - 2>&1 | sed -n 's,^ ,,p'"
		OUTPUT_VARIABLE SYS_INCLUDE_DIRS
	)
	string(REPLACE "\n" ";" SYS_INCLUDE_DIRS "${SYS_INCLUDE_DIRS}")

	find_path(
		STD_MODULES_SRC_DIR
		NAMES bits/std.cc
		PATHS ${SYS_INCLUDE_DIRS}
		PATH_SUFFIXES "c++/${CMAKE_CXX_COMPILER_VERSION}"
		REQUIRED NO_DEFAULT_PATH
	)

	add_library(std)
	target_sources(std PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS ${STD_MODULES_SRC_DIR}/bits
		FILES
			${STD_MODULES_SRC_DIR}/bits/std.cc
			${STD_MODULES_SRC_DIR}/bits/std.compat.cc
	)
	link_libraries(std)
else()
	message(FATAL_ERROR "C++23 Standard library module is not supported with current compiler.")
endif()