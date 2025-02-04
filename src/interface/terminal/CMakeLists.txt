cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCES "./*.c")
file(GLOB_RECURSE HEADERS "./*.h")
add_library(chess_terminal ${SOURCES} ${HEADERS})
target_include_directories(chess_terminal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
