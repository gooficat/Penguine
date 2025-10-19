#ifndef APP_H
#define APP_H

#include "global.h"

#include "window.h"
#include "event.h"

#include "render/renderer.h"

#include "scene.h"

class App {
public:
    App();
    ~App();
    void run();
    void changeScene(const std::string& name);
    inline static App *active_instance;
protected:
    Window *window;
    EventHandler *event_handler;
    Renderer *renderer;

    std::string active_scene;
    std::map<std::string, std::shared_ptr<Scene>> scenes;
private:
    uint16_t width, height;
};

#endif