#define RGFW_OPENGL
#include "render/renderer.h"

void Renderer::init(Window *window) {
    this->context_window = window->getInternalWindow();
    // RGFW_window_createContext_OpenGL(context_window, window->getHints());
    glfwMakeContextCurrent(context_window);
    // RGFW_window_swapInterval_OpenGL(context_window, 0);
    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cerr << "Failed to load OpenGL" << std::endl;
    }
    setSize(0, window->getWidth(), 0, window->getHeight());
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
}

void Renderer::beginDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::endDraw() {
    glfwSwapBuffers(context_window);
}

void Renderer::setSize(uint16_t left, uint16_t right, uint16_t up, uint16_t down) {
    glViewport(left, up, right, down);
}