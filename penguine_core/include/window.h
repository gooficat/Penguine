#pragma once

#include "global.h"

class Window {
public:
    Window();
    void init();
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    RGFW_window *getInternalWindow();
private:
    RGFW_window *window;
    uint16_t width;
    uint16_t height;
    static Window *active_instance;
};