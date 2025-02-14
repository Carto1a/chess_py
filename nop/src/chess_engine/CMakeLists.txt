cmake_minimum_required(VERSION 3.20)

project(chess_engine VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

add_library(chess_engine SHARED ${SOURCES} ${HEADERS})

target_include_directories(chess_engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(chess_engine PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)
