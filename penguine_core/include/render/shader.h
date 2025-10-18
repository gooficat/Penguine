#pragma once

#include "global.h"
#include "resource.h"

enum ShaderType {
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    FRAGMENT_SHADER,
};

struct ShaderResource : public Resource {
    ShaderResource(const std::string& path, const ShaderType& type);
    void Load();
    ~ShaderResource();
    GLuint GetID();
private:
    GLuint ID;
};

class ShaderProgram {
public:
    ShaderProgram();
private:
};