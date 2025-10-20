#include "scene.h"

void Scene::tickCallback(double delta_time) {
    for (auto& tickable : tickables) {
        tickable.second->tick(delta_time);
    }
}

void Scene::draw() {
    for (auto& layer : layers) {
        layer->render();
    }
}

void Scene::addTickable(const std::string& name, std::shared_ptr<Tickable>& tickable) {
    tickables.insert({name, tickable});
}

void Scene::addLayer(std::shared_ptr<Camera>& camera, std::shared_ptr<ShaderProgram>& shader_program) {
    this->layers.push_back(std::make_unique<Layer>(camera, shader_program));
}