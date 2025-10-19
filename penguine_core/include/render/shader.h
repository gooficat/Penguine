#ifndef SHADER_H
#define SHADER_H

#include "global.h"
#include "resource.h"

enum ShaderType {
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    FRAGMENT_SHADER,
};

struct ShaderResource : public Resource {
    ShaderResource(const std::string& path, const ShaderType& type);
    void load();
    ~ShaderResource();
    GLuint getID();
private:
    GLuint ID;
    std::string path;
    ShaderType type;
};

class ShaderProgram {
public:
    ShaderProgram(const std::vector<const ShaderResource&>& shaders);
    
    void use() const;

    void setInt(const std::string& name, GLint value) const;

    void setFloat(const std::string& name, GLfloat value) const;
    void setFloat2(const std::string& name, float2 value) const;
    void setFloat3(const std::string& name, float3 value) const;
    void setFloat4(const std::string& name, float4 value) const;

    void setFloat4x4(const std::string& name, float4x4 value) const;

    GLint findUniform(const std::string& name) const;
private:
    GLuint ID;
};

#endif