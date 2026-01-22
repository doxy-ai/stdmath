include(../cmake/fetchDoctest.cmake)

add_executable(stdmath_test angle.cpp vector.cpp matrix.cpp)
target_link_libraries(stdmath_test PUBLIC stdmath doctest)