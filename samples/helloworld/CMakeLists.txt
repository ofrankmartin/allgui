cmake_minimum_required(VERSION 3.14)

set(TARGET "helloworld")

project(${TARGET} CXX)

find_package(SDL2 REQUIRED)

set(SOURCES main.cpp)

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} allgui)
target_link_libraries(${TARGET} SDL2)
