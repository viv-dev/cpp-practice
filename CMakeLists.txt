cmake_minimum_required(VERSION 3.0.0)
project(practice VERSION 0.1.0)

include(conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)
enable_testing()

add_executable(practice "src/main.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
