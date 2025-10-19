#ifndef EVENT_H
#define EVENT_H

#include "global.h"

#include "window.h"

class EventHandler {
public:
    EventHandler();
    bool IsKeyDown(uint8_t key);

    void Update();

    float mouse_x;
    float mouse_y;
private:
    RGFW_event event;
};

#endif