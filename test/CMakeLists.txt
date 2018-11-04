set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

message("GTEST_INCLUDE_DIRS = " ${GTEST_INCLUDE_DIRS})
message("GTEST_LIBRARIES = " ${GTEST_LIBRARIES})

include_directories(${GTEST_INCLUDE_DIRS})
#include(GoogleTest)

#include_directories(../bridge_mf/inc)

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (Bridge_MF_test gtest_main.cc Handtest.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (Bridge_MF_test bridge_mf ${GTEST_LIBRARIES})
