#include "event.h"

EventHandler::EventHandler(Window *window) {
    this->active_window = window;
}

bool EventHandler::isKeyDown(uint8_t key) {
    return (glfwGetKey(active_window->getInternalWindow(), key));
}

void EventHandler::update() {
    // RGFW_pollEvents();
    glfwPollEvents();
    // RGFW_getMouseVector(&mouse_x, &mouse_y);
    glfwGetCursorPos(active_window->getInternalWindow(), &mouse_x, &mouse_y);
}