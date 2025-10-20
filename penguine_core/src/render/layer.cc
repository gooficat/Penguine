#include "render/layer.h"

Layer::Layer(std::shared_ptr<Camera>& camera, std::shared_ptr<ShaderProgram>& shader_program) :
    camera(camera), shader_program(shader_program) {
    
}
void Layer::addViewable(const std::string& name, std::shared_ptr<Viewable>& viewable) {
    viewables.insert({name, viewable});
}

void Layer::render() {
    shader_program->use();
    for (auto& viewable : viewables) {
        viewable.second.get()->render();
    }
}