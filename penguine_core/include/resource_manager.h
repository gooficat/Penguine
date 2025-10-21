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
    void load(const string& asset_pack_path, const string& entity_pack_path);

    std::map<string, shared_ptr<Resource>> resources;

    std::map<string, shared_ptr<Camera>> cameras;
    std::map<string, shared_ptr<Tickable>> tickables;
    std::map<string, shared_ptr<Viewable>> viewables;
private:

};