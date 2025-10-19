#include "app.h"

App::App() {
    this->window = new Window();
    this->event_handler = new EventHandler();
    this->renderer = new Renderer();
    App::active_instance = this;
}

void App::run() {
    window->init();
    renderer->init(window);
    while (true) { // scary i know
        renderer->beginDraw();

        renderer->endDraw();
        event_handler->update();
    }
}

App::~App() {

}