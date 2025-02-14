cmake_minimum_required(VERSION 3.20)

project(chess_ui_terminal VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE SOURCES "./*.c")
file(GLOB_RECURSE HEADERS "./*.h")
add_library(chess_ui_terminal SHARED ${SOURCES} ${HEADERS})

target_include_directories(chess_ui_terminal PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(chess_ui_terminal PRIVATE common)

set_target_properties(chess_ui_terminal PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)
