#pragma once

#include "global.h"

#include "render/mesh.h"

class Viewable {
public:
    Viewable();
    virtual void render();
protected:
private:
};

class MeshViewable : public Viewable {
public:
    MeshViewable(std::shared_ptr<MeshResource>& mesh);
    void render();
    std::shared_ptr<MeshResource> mesh;
};