#include "event.h"

EventHandler::EventHandler() {}

bool EventHandler::IsKeyDown(uint8_t key) {
    return (RGFW_isKeyDown(key));
}

void EventHandler::Update() {
    RGFW_pollEvents();
    RGFW_getMouseVector(&mouse_x, &mouse_y);
}