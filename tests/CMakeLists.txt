include(../cmake/fetchDoctest.cmake)

if(MSVC)
    add_executable(stdmath_test angle.cpp vector.cpp matrix.cpp)# quaternion.cpp)
else()
    add_executable(stdmath_test angle.cpp vector.cpp matrix.cpp quaternion.cpp)
endif()
target_link_libraries(stdmath_test PUBLIC stdmath doctest)