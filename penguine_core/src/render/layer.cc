#include "render/layer.h"

Layer::Layer(std::shared_ptr<Camera> camera, std::shared_ptr<ShaderProgram> shader_program) :
    camera(camera), shader_program(shader_program) {
    
}
void Layer::addViewable(const std::string& name, Viewable *viewable) {
    viewables.insert({name, std::make_shared<Viewable>()});
}

void Layer::render() {
    for (auto& viewable : viewables) {
        viewable.second.get()->render();
    }
}