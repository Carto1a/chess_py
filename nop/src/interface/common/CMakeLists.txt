cmake_minimum_required(VERSION 3.20)

project(common_library LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/common.h")

if(UNIX)
    file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/unix.c")
elseif(WIN32)
    file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/windows.c")
else()
    message(FATAL_ERROR "Unsupported platform!")
endif()

add_library(common STATIC)
target_sources(common PRIVATE ${SOURCES} ${HEADERS})

target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

if(MSVC)
    target_compile_options(common PRIVATE /W4)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(common PRIVATE -Wall -Wextra -pedantic)
endif()
