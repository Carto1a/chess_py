cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME chess_engine)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE)
    set(default_build_type "Debug")
    message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
    set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Choose the build type." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")

message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

add_library(chess_engine SHARED ${SOURCES} ${HEADERS})

target_include_directories(chess_engine PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

set_target_properties(chess_engine PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

