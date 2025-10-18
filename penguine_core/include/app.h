#pragma once

#include "global.h"

#include "window.h"
#include "event.h"

class App {
public:
    App();
    ~App();
    void run();
protected:
    Window *window;
    EventHandler *event_handler;
private:
    uint16_t width, height;
    static App *active_instance;
};