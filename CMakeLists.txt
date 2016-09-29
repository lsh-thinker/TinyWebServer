cmake_minimum_required (VERSION 3.6)
project(TinyWebServer CXX)

# The version number
set (TINY_WEB_SERVER_VERSION_MAJOR 1)
set (TINY_WEB_SERVER_VERSION_MINOR 0)

message(status " BINARY DIR: " ${PROJECT_BINARY_DIR})
message(status " SOURCE DIR: " ${PROJECT_SOURCE_DIR})

# configure a header file to pass some of the CMake settings to the source code
#configure_file(
#  "${PROJECT_SOURCE_DIR}/src/tiny_config.h.in"
#  "${PROJECT_BINARY_DIR}/src/tiny_config.h"
#) 
# add the binary tree to the search path for include files
# so that we will find tiny_config.h

#include_directories("${PROJECT_BINARY_DIR}")

ADD_SUBDIRECTORY(src bin)
