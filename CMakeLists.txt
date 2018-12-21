cmake_minimum_required (VERSION 2.8.11)
project (BRIDGE_MF)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_MACOSX_RPATH 1)

add_subdirectory (lib)
add_subdirectory (test)
add_subdirectory (demo)

