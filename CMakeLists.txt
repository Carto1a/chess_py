cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME chess)
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

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

# target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/interface/include")

# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/common")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/interface")
# add_subdirectory("src/chess_engine")

set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /DEBUG)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -g)
endif()

# target_link_libraries(${PROJECT_NAME} PUBLIC chess_ui_terminal)
# target_link_libraries(${PROJECT_NAME} PRIVATE chess_ui_terminal)
