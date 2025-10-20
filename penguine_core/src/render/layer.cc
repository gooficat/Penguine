#include "render/layer.h"

Layer::Layer(shared_ptr<Camera>& camera, shared_ptr<ShaderProgram>& shader_program) :
    camera(camera), shader_program(shader_program) {
    
}
void Layer::addViewable(const string& name, shared_ptr<Viewable>& viewable) {
    viewables.insert({name, viewable});
}

void Layer::render() {
    shader_program->use();
    for (auto& viewable : viewables) {
        viewable.second.get()->render(*(shader_program.get()));
    }
}