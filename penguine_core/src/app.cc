#include "app.h"

App::App() {
    this->window = new Window();
    this->event_handler = new EventHandler(window);
    this->renderer = new Renderer();
    App::active_instance = this;
    window->init();
    renderer->init(window); // i am so infuriated right now i am so infuriated
}

void App::changeScene(const std::string& name) {
    if (scenes.at(name)) {
    this->active_scene = name;
    }
    else {
        std::cerr << "Tried to change scenes but there is no scene named " << name << std::endl;
    }
}

void App::run() {
    window->init();
    renderer->init(window);
    while (!RGFW_window_shouldClose(window->getInternalWindow())) { // scary i know
        renderer->beginDraw();

        this->scenes.at(active_scene)->draw();

        renderer->endDraw();
        event_handler->update();
    }
}

App::~App() {

}