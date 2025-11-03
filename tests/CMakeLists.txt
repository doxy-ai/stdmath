include(../cmake/fetchDoctest.cmake)

add_executable(stdmath_test vector.cpp matrix.cpp angles.cpp quaternion.cpp)
target_link_libraries(stdmath_test PUBLIC stdmath doctest)