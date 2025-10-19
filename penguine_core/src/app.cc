#include "app.h"

App::App() {
    this->window = new Window();
    this->event_handler = new EventHandler();
    App::active_instance = this;
}

void App::run() {
    window->init();
    while (true) { // scary i know

    }
}

App::~App() {

}