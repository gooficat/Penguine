#ifndef APP_H
#define APP_H

#include "global.h"

#include "window.h"
#include "event.h"

#include "render/renderer.h"

#include "scene.h"

#include "render/mesh.h"

#include "resource.h"

#include "resource_manager.h"

class App {
public:
    App(const string& path);
    ~App();
    void run();
    void changeScene(const string& name);
    inline static App *active_instance;

    void addScene(const string& path);
protected:
    unique_ptr<Window> window;
    unique_ptr<EventHandler> event_handler;
    unique_ptr<Renderer> renderer;
    unique_ptr<ResourceManager> resource_manager;
    

    string active_scene;
    std::map<string, shared_ptr<Scene>> scenes;
private:
    uint16_t width, height;
};

#endif