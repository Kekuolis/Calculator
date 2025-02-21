cmake_minimum_required(VERSION 3.25.1)

project(Task)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Task main.cpp expression.cpp)

add_executable(TaskTests tests.cpp expression.cpp)  
add_test(NAME TaskTests COMMAND TaskTests)

target_link_libraries(TaskTests PRIVATE GTest::GTest GTest::Main pthread)