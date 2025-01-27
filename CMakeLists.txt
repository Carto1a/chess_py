cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME chess)

project(${PROJECT_NAME})

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/Wall)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif()

add_executable(${PROJECT_NAME} "./src/main.c")

add_subdirectory("src/interface/terminal")
add_subdirectory("src/chess_engine")

target_link_libraries(${PROJECT_NAME} PUBLIC chess_terminal chess_engine)
