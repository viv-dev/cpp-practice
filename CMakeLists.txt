cmake_minimum_required(VERSION 3.13)
project(viv-practice VERSION 0.1.0)

# Grab include paths from conan install for dependencies
include(conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${CONAN_INCLUDE_DIRS})

# Create our executable
# add_executable(viv-practice "")
# target_link_libraries(viv-practice PUBLIC ${CONAN_LIBS} viv-functions)
# target_compile_definitions(viv-practice PUBLIC DOCTEST_CONFIG_DISABLE)

add_subdirectory(src)

 # Set up a test that calls our testing executable
include(CTest)
enable_testing()
add_subdirectory(test)
add_test(PracticeTests tester)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
