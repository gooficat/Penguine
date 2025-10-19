#include "event.h"

EventHandler::EventHandler() {}

bool EventHandler::isKeyDown(uint8_t key) {
    return (RGFW_isKeyDown(key));
}

void EventHandler::update() {
    RGFW_pollEvents();
    RGFW_getMouseVector(&mouse_x, &mouse_y);
}