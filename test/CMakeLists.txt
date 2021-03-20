cmake_minimum_required(VERSION 3.13)

add_executable(tester main.cpp)
target_link_libraries(tester PUBLIC ${CONAN_LIBS} viv-functions viv-logic)
