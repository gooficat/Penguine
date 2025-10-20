#pragma once

#include "render/layer.h"
#include "render/camera.h"
#include "render/mesh.h"
#include "render/shader.h"
#include "render/texture.h"
#include "entity/tickable.h"
#include "entity/viewable.h"

class ResourceManager {
public:
    ResourceManager();
    void load(const string& path);

    std::map<string, shared_ptr<Resource>> resources;
private:

};