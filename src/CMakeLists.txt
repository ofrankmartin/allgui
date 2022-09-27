cmake_minimum_required(VERSION 3.14)

set(TARGET "allgui")

project(${TARGET} CXX)

set(SOURCES 
    # Interfaces
    api/Director.cpp
    api/Factory.cpp
    api/Window.cpp
    api/Scene.cpp
    # Impementation interfaces
    api/DirectorImpl.cpp
    # SDL2 Backend
    backends/SDL2/DirectorSDL2.cpp
    backends/SDL2/FactoryImplSDL2.cpp
    backends/SDL2/WindowSDL2.cpp
    backends/SDL2/SceneSDL2.cpp
    )

add_library(${TARGET} SHARED ${SOURCES})

target_include_directories(${TARGET} PUBLIC api)
