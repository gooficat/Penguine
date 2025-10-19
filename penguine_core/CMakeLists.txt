cmake_minimum_required(VERSION 3.10)
project(penguine_core)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # this is probably arbitrary here, i'm not sure what standard i actually use

include_directories(${CMAKE_SOURCE_DIR})
include_directories(include)

# add_compile_definitions(RGFW_IMPLEMENTATION)
add_compile_definitions(RGFW_OPENGL)
add_compile_definitions(LINALG_FORWARD_COMPATIBLE)

add_executable(penguine_core
    src/impl/glad.c
    src/impl/rgfw.c

    src/main.cc


    src/app.cc
    src/event.cc
    src/window.cc
    src/resource.cc

    src/render/shader.cc
)


target_link_libraries(penguine_core
    opengl32
    gdi32
)