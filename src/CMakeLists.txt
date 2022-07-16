set(LIB_SOURCES
        ${PROJECT_SOURCE_DIR}/src/lib/src/print.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/compose.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/factory.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/convert.cpp config.cpp processing.cpp)

add_library(small_lib STATIC ${LIB_SOURCES})

set(SOURCES
        main.cpp
        config.cpp
        processing.cpp)

add_executable(${CMAKE_PROJECT_NAME}  ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} small_lib)