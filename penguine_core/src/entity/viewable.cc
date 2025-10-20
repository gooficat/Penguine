#include "entity/viewable.h"

Viewable::Viewable() {
    
}

void Viewable::render(const ShaderProgram& shader_program) {
    std::cout << "I am being \'viewed\'" << std::endl;
}

MeshViewable::MeshViewable(shared_ptr<MeshResource>& mesh) : mesh(mesh), matrix(linalg::identity) {
}

void MeshViewable::render(const ShaderProgram& shader_program) {
    shader_program.setFloat4x4("model", matrix);
    this->mesh->draw();
}