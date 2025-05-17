include(../cmake/fetchDoctest.cmake)

add_executable(stdmath_test vec.cpp mat.cpp angles.cpp)
target_link_libraries(stdmath_test PUBLIC stdmath doctest)