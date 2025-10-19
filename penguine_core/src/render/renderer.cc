#include "render/renderer.h"

void Renderer::init(Window *window) {

}

void Renderer::beginDraw() {
    
}

void Renderer::endDraw() {
    
}

void Renderer::setSize(uint16_t left, uint16_t right, uint16_t up, uint16_t down) {
    glViewport(left, up, right, down);
}