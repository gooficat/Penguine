#include "app.h"

App::App() {
    this->window = new Window();
    this->event_handler = new EventHandler();
    this->active_instance = this;
}

void App::run() {
    window->init();
}

App::~App() {

}