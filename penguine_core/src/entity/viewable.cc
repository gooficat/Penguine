#include "entity/viewable.h"

Viewable::Viewable() {

}

void Viewable::render() {
    std::cout << "I am being \'viewed\'" << std::endl;
}

MeshViewable::MeshViewable(std::shared_ptr<MeshResource>& mesh) : mesh(mesh) {

}

void MeshViewable::render() {
    this->mesh->draw();
}