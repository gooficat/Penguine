#ifndef APP_H
#define APP_H

#include "global.h"

#include "window.h"
#include "event.h"

class App {
public:
    App();
    ~App();
    void run();
    // static App *active_instance;
protected:
    Window *window;
    EventHandler *event_handler;
private:
    uint16_t width, height;
};

#endif