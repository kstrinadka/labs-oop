cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

add_executable(lab1 test.cpp TritSet.cpp TritSet.h Trit.cpp Trit.h)

target_link_libraries(lab1 gtest gtest_main)

