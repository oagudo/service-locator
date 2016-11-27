cmake_minimum_required (VERSION 2.8)
project (ServiceLocator)

# Set compiler flags and options.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++1y") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

FILE(GLOB_RECURSE SOURCES "main.cpp")

# Include Directories
include_directories (./include) 

add_executable (exe ${SOURCES})
