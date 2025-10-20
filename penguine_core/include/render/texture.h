#pragma once

#include "global.h"

#include "resource.h"

struct Texture : public Resource {
    GLuint ID;
    string type;
    Texture(const string& path);
    ~Texture();
    void load();
};