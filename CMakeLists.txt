cmake_minimum_required(VERSION 3.14)

set(TARGET "allgui_lib")

project(${TARGET} CXX)

option(BUILD_SAMPLES "Build the sample projects" ON)

add_subdirectory(src)

if (BUILD_SAMPLES)
    add_subdirectory(samples/helloworld)
endif()