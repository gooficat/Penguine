#ifndef RENDERER_H
#define RENDERER_H

#include "global.h"

#include "window.h"

class Renderer {
public:
    Renderer() = default;
    void init(Window *window);
    
    void beginDraw();
    void endDraw();

    void setSize(uint16_t left, uint16_t right, uint16_t up, uint16_t down);
private:
    GLFWwindow *context_window;
};

#endif