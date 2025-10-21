#include "app.h"

App::App(const string& path) {
    this->window = make_unique<Window>();
    this->event_handler = make_unique<EventHandler>(window.get());
    this->renderer = make_unique<Renderer>();
    this->resource_manager = make_unique<ResourceManager>();
    App::active_instance = this;
    window->init();
    renderer->init(window.get()); // i am so infuriated right now i am so infuriated

    std::ifstream file(path);
    nlohmann::json data = nlohmann::json::parse(file);
    file.close();

    resource_manager->load(data["asset_pack"], data["entities"]);

    for (auto& scene : data.at("scenes")) {
        std::cout << "load scene" << std::endl;
        addScene(scene);
    }
}

void App::changeScene(const string& name) {
    if (scenes.at(name)) {
    this->active_scene = name;
    }
    else {
        std::cerr << "Tried to change scenes but there is no scene named " << name << std::endl;
    }
}

void App::run() {
    while (!RGFW_window_shouldClose(window->getInternalWindow())) { // scary i know

        this->scenes.at(active_scene)->tickCallback(1.0);

        renderer->beginDraw();

        this->scenes.at(active_scene)->draw();

        renderer->endDraw();
        event_handler->update();

    }
}

App::~App() {

}


void App::addScene(const string& path) {
    std::ifstream f(path);
    nlohmann::json j = nlohmann::json::parse(f);
    f.close();

    scenes.insert({j.at("name"), make_shared<Scene>()});

    std::cout << path << scenes.at(j.at("name")) << std::endl;
    
    for (auto& layer : j["layers"]) {
            
        scenes.at(j.at("name"))->addLayer(
            resource_manager->cameras[layer.at("camera")],
            resource_manager->programs[layer.at("shader_program")]
        );
        for (auto& viewable : layer.at("viewables")) {
            scenes.at(j.at("name"))->layers.front()->addViewable(
                viewable,
                resource_manager->viewables[viewable]
            );
        }
    }
    changeScene(j.at("name"));
}