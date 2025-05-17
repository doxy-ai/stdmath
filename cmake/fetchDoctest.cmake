include(FetchContent)

FetchContent_Declare(
	doctest

	# Manual download mode, even shallower than GIT_SHALLOW ON
	DOWNLOAD_COMMAND
		cd ${FETCHCONTENT_BASE_DIR}/doctest-src &&
		git init &&
		git fetch --depth=1 https://github.com/doctest/doctest.git &&
		git reset --hard FETCH_HEAD &&
		git submodule update --depth 1 --init --recursive

	# PATCH_COMMAND
	# 	git apply --ignore-space-change --ignore-whitespace "${CMAKE_CURRENT_SOURCE_DIR}/patches/stdblas.patch"
)
FetchContent_MakeAvailable(doctest)