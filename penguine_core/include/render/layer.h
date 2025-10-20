#pragma once

#include "global.h"

#include "entity/viewable.h"
#include "render/shader.h"
#include "render/camera.h"

class Layer {
public:
    Layer(shared_ptr<Camera>& camera, shared_ptr<ShaderProgram>& shader_program);
    void addViewable(const string& name, shared_ptr<Viewable>& viewable);

    void render();

    shared_ptr<Camera> camera;
    shared_ptr<ShaderProgram> shader_program;
    std::map<string, shared_ptr<Viewable>> viewables;
private:
};