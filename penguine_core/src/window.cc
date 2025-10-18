#include "window.h"

Window::Window() {

}
void Window::init() {
    this->width = 640;
    this->height = 360;
    this->window = RGFW_createWindow(
        "", 0, 0, width, height, 
        RGFW_windowCenter | RGFW_windowNoResize | RGFW_windowOpenGL
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