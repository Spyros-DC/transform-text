# 3.14 is required as min because of the FetchContent module
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(transformText)

include_directories(${PROJECT_SOURCE_DIR}/src/lib/include/)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)

add_subdirectory(test)