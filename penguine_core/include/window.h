#ifndef WINDOW_H
#define WINDOW_H
#include "global.h"

class Window {
public:
    // static Window *active_instance;
    Window();
    void init();
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    RGFW_window *getInternalWindow();
    Window *getActiveInstance();
    RGFW_glHints *getHints();
private:
    RGFW_window *window;
    RGFW_glHints *hints;
    uint16_t width;
    uint16_t height;
};

#endif