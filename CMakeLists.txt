cmake_minimum_required(VERSION 3.13)
project(viv-practice VERSION 0.1.0)

include(conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)
enable_testing()

include_directories(${CONAN_INCLUDE_DIRS})

add_executable(viv-practice "")
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
