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

void Scene::addTickable(const string& name, shared_ptr<Tickable>& tickable) {
    tickables.insert({name, tickable});
}

void Scene::addLayer(shared_ptr<Camera>& camera, shared_ptr<ShaderProgram>& shader_program) {
    this->layers.push_back(make_unique<Layer>(camera, shader_program));
}