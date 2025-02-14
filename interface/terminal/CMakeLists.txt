file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(chess_ui_terminal SHARED ${SOURCES} ${HEADERS})

target_include_directories(chess_ui_terminal PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(chess_ui_terminal PUBLIC "../include")

set_target_properties(chess_ui_terminal PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)
