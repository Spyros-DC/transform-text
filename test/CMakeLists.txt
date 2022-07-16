#include cmake module
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/4556086674e4dfae2aa5f042d9e7844fc5ef9b89.zip
)

FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES 
    factoryTests.cpp
    composeTests.cpp
    convertTests.cpp
    wordsTests.cpp
    configTests.cpp
    processingTests.cpp)

add_executable(${CMAKE_PROJECT_NAME}Tests  ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}Tests gtest_main small_lib)