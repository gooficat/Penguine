#ifndef EVENT_H
#define EVENT_H

#include "global.h"

#include "window.h"

class EventHandler {
public:
    EventHandler();
    bool isKeyDown(uint8_t key);

    void update();

    float mouse_x;
    float mouse_y;
private:
    RGFW_event event;
};

#endif