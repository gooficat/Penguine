cmake_minimum_required(VERSION 3.10)
project(penguine_core)
enable_language(CXX)
enable_language(C)
set(CMAKE_CXX_STANDARD 17) # this is probably arbitrary here, i'm not sure what standard i actually use
set(CMAKE_C_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(include)

# file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "src/*")

# add_subdirectory()

add_executable(penguine_core
    src/entity/tickable.cc
    src/entity/viewable.cc

    src/render/camera.cc
    src/render/layer.cc
    src/render/renderer.cc
    src/render/shader.cc
    src/render/mesh.cc
    src/render/texture.cc

    src/app.cc
    src/event.cc
    src/main.cc
    src/resource.cc
    src/scene.cc
    src/window.cc


    src/impl/glad.c
    src/impl/rgfw.c
    src/impl/stb_image.c
)

target_link_directories(penguine_core
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib
)

target_link_libraries(penguine_core
    opengl32
    # glfw3
    gdi32
)

# add_compile_options("-w")
# set(CMAKE_BUILD_TYPE Debug)
