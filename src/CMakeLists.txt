set(LIB_SOURCES
        ${PROJECT_SOURCE_DIR}/src/lib/src/print.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/compose.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/factory.cpp
        ${PROJECT_SOURCE_DIR}/src/lib/src/convert.cpp config.cpp porcessing.cpp)

add_library(small_lib STATIC ${LIB_SOURCES})