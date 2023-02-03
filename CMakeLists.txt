cmake_minimum_required(VERSION 3.24)
project(lla)

find_package(Catch2 3 REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
target_include_directories(${PROJECT_NAME} INTERFACE include)

file(GLOB_RECURSE TEST_FILES test/*.cpp)
add_executable(${PROJECT_NAME}_test ${TEST_FILES})
set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 17)
target_include_directories(${PROJECT_NAME}_test PRIVATE include)
target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2WithMain)
