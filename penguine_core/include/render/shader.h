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
    ShaderResource(const string& path, const ShaderType& type);
    void load();
    ~ShaderResource();
    GLuint getID() const;
    GLuint ID;
private:
    ShaderType type;
};

class ShaderProgram {
public:
    ShaderProgram(const ShaderResource& vertex_shader, const ShaderResource& fragment_shader);
    
    void use() const;

    void setInt(const string& name, GLint value) const;

    void setFloat(const string& name, GLfloat value) const;
    void setFloat2(const string& name, float2 value) const;
    void setFloat3(const string& name, float3 value) const;
    void setFloat4(const string& name, float4 value) const;

    void setFloat4x4(const string& name, float4x4 value) const;

    GLint findUniform(const string& name) const;
private:
    GLuint ID;
};

#endif