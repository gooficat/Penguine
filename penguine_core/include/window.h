#ifndef WINDOW_H
#define WINDOW_H
#include "global.h"

class Window {
public:
    Window();
    void init();
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    GLFWwindow *getInternalWindow();
    Window *getActiveInstance();
    // static Window *active_instance;
private:
    GLFWwindow *window;
    uint16_t width;
    uint16_t height;
};

#endif