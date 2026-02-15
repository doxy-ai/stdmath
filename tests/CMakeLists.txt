include(../cmake/fetchDoctest.cmake)

if(MSVC)
    add_executable(stdmath_test angle.cpp vector.cpp vector.c.cpp matrix.cpp AABB.cpp color.cpp matrix_transformations.cpp)# quaternion.cpp)
else()
    add_executable(stdmath_test angle.cpp vector.cpp vector.c.cpp matrix.cpp quaternion.cpp AABB.cpp color.cpp matrix_transformations.cpp)
endif()
target_link_libraries(stdmath_test PUBLIC stdmath doctest)