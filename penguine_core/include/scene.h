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

    void addTickable(const string& name, shared_ptr<Tickable>& tickable);
    
    void addLayer(shared_ptr<Camera>& camera, shared_ptr<ShaderProgram>& shader_program);

    std::map<string, shared_ptr<Tickable>> tickables;
    std::vector<unique_ptr<Layer>> layers;
protected:
private:
};