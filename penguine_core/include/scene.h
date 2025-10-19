#pragma once

#include "global.h"

#include "entity/tickable.h"
#include "entity/viewable.h"

#include "render/layer.h"

class Scene {
public:
    Scene() = default;
    void tickCallback(double delta_time);
    void draw();

    void addTickable(const std::string& name, Tickable *tickable);
    
    void addLayer(std::shared_ptr<Camera> camera, std::shared_ptr<ShaderProgram> shader_program);

    std::map<std::string, std::shared_ptr<Tickable>> tickables;
    std::vector<std::unique_ptr<Layer>> layers;
protected:
private:
};