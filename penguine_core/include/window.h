#ifndef WINDOW_H
#define WINDOW_H
#include "global.h"

class Window {
public:
    Window();
    void init();
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    RGFW_window *getInternalWindow();
    RGFW_glHints *getHints();
private:
    RGFW_window *window;
    RGFW_glHints *hints;
    uint16_t width;
    uint16_t height;
    static Window *active_instance;
};

#endif