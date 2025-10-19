#include "window.h"

Window::Window() {
    // Window::active_instance = this;
}
void Window::init() {
    this->width = 640;
    this->height = 360;

    this->hints = RGFW_getGlobalHints_OpenGL();
    hints->major = 3;
    hints->minor = 3;
    RGFW_setGlobalHints_OpenGL(this->hints);

    this->window = RGFW_createWindow(
        "", 0, 0, width, height, 
        RGFW_windowAllowDND | RGFW_windowCenter | RGFW_windowNoResize | RGFW_windowOpenGL // should add resizing later, but it's
    );
}
uint16_t Window::getWidth() const {
    return this->width;
}
uint16_t Window::getHeight() const {
    return this->height;
}
RGFW_window *Window::getInternalWindow() {
    return this->window;
}

RGFW_glHints *Window::getHints() {
    return this->hints;
}

Window *Window::getActiveInstance() {
    return this;// haha goteem Window::active_instance;
}