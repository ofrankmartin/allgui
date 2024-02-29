cmake_minimum_required(VERSION 3.14)

set(TARGET "allgui")

project(${TARGET} CXX)

set(SOURCES
    # Interfaces
    api/Director.cpp
    api/Factory.cpp
    api/Window.cpp
    api/Scene.cpp
    # Implementation interfaces
    api/DirectorImpl.cpp
    # SDL2 Backend
    backends/SDL2/DirectorSDL2.cpp
    backends/SDL2/FactoryImplSDL2.cpp
    backends/SDL2/WindowSDL2.cpp
    backends/SDL2/SceneSDL2.cpp
)

set(HEADERS
    # Tools
    api/Exception.h 
    # Interfaces
    api/Director.h
    api/Factory.h
    api/Window.h
    api/Scene.h
    # Implementation interfaces
    api/DirectorImpl.h
    # SDL2 Backend
    backends/SDL2/DirectorSDL2.h
    backends/SDL2/FactoryImplSDL2.h
    backends/SDL2/WindowSDL2.h
    backends/SDL2/SceneSDL2.h
)

add_library(${TARGET} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${TARGET} PUBLIC api)
