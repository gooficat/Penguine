#include "window.h"

Window::Window() {
    // Window::active_instance = this;
}
void Window::init() {
    this->width = 640;
    this->height = 360;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(
        width, height, "",
        NULL, NULL // should add resizing later, but it's a pain
    );
}
uint16_t Window::getWidth() const {
    return this->width;
}
uint16_t Window::getHeight() const {
    return this->height;
}
GLFWwindow *Window::getInternalWindow() {
    return this->window;
}


Window *Window::getActiveInstance() {
    // return Window::active_instance;
    return this;
}