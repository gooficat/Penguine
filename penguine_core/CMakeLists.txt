cmake_minimum_required(VERSION 3.10)
project(penguine_core)
enable_language(CXX)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(include)

add_executable(penguine_core
    src/impl/glad.c
    src/impl/rgfw.c

    src/main.cc
    src/app.cc
)

target_link_libraries(penguine_core
    opengl32
    gdi32
)