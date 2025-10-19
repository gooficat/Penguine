#pragma once

#include "global.h"

#include "entity/viewable.h"
#include "render/shader.h"
#include "render/camera.h"

class Layer {
public:
    Layer(std::shared_ptr<Camera> camera, std::shared_ptr<ShaderProgram> shader_program);
    void addViewable(const std::string& name, Viewable *viewable);

    void render();

    std::shared_ptr<Camera> camera;
    std::shared_ptr<ShaderProgram> shader_program;
    std::map<std::string, std::shared_ptr<Viewable>> viewables;
private:
};