include(FetchContent)

FetchContent_Declare(
	fetch_doctest
	GIT_REPOSITORY https://github.com/doctest/doctest.git
)
FetchContent_MakeAvailable(fetch_doctest)