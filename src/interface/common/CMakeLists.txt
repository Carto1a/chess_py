cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE HEADERS "*.h")

if(UNIX)
    file(GLOB_RECURSE SOURCES "unix.c")
elseif(WIN32)
    file(GLOB_RECURSE SOURCES "windows.c")
endif()

add_library(common ${SOURCES} ${HEADERS})
