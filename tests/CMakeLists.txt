include(../cmake/fetchDoctest.cmake)

add_executable(stdmath_test vector.cpp)
target_link_libraries(stdmath_test PUBLIC stdmath doctest)