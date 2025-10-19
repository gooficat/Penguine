#ifndef APP_H
#define APP_H

#include "global.h"

#include "window.h"
#include "event.h"

#include "render/renderer.h"

class App {
public:
    App();
    ~App();
    void run();
    inline static App *active_instance;
protected:
    Window *window;
    EventHandler *event_handler;
    Renderer *renderer;
private:
    uint16_t width, height;
};

#endif