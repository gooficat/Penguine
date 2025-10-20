#pragma once

#include "global.h"

#include "resource.h"

struct Texture : public Resource {
    GLuint ID;
    std::string type;
    Texture(const std::string& path);
    ~Texture();
    void load();
};