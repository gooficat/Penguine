#ifndef VIEWABLE_H_
#define VIEWABLE_H_

#include "global.h"

#include "render/mesh.h"

#include "render/shader.h"

class Viewable {
public:
    Viewable();
    virtual void render(const ShaderProgram& shader_program);
protected:
private:
};

class MeshViewable : public Viewable {
public:
    MeshViewable(MeshResource& mesh);
    void render(const ShaderProgram& shader_program);
    shared_ptr<MeshResource> mesh;
    float4x4 matrix;
};

#endif