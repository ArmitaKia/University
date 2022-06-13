cmake_minimum_required(VERSION 3.0.0)
project(universityTest VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(universityTest main.cpp Course.h Course.cpp Person.h Person.cpp Student.h Student.cpp Professor.h Professor.cpp University.h University.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
