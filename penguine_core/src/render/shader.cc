#include "render/shader.h"

ShaderResource::ShaderResource(const std::string& path, const ShaderType& type) :
    Resource(path), type(type) {
}

void ShaderResource::load() {
    this->ID = glCreateShader(
        (type == VERTEX_SHADER) ? GL_VERTEX_SHADER :
        (type == GEOMETRY_SHADER) ? GL_GEOMETRY_SHADER :
      /*(type == FRAGMENT_SHADER) ?*/ GL_FRAGMENT_SHADER
    );
    std::string content = ::Resource::loadTextFile(path);
    const char* source = content.c_str();
    glShaderSource(ID, 1, &source, NULL);
    glCompileShader(ID);
}

ShaderResource::~ShaderResource() {
    glDeleteShader(this->ID);
}

GLuint ShaderResource::getID() {
    return this->ID;
}

ShaderProgram::ShaderProgram(const std::vector<const ShaderResource&>& shaders) {
    this->ID = glCreateProgram();
    glUseProgram(this->ID);

    for (auto& shader : shaders) {
        glAttachShader(this->ID, shader.getID());
    }
    glLinkProgram(this->ID);
}

void ShaderProgram::use() const {
    glUseProgram(this->ID);
}


void ShaderProgram::setInt(const std::string& name, GLint value) const {
    glUniform1i(findUniform(name), value);
}

void ShaderProgram::setFloat(const std::string& name, GLfloat value) const {
    glUniform1f(findUniform(name), value);
}
void ShaderProgram::setFloat2(const std::string& name, float2 value) const {
    glUniform2fv(findUniform(name), 1, &value[0]);
}
void ShaderProgram::setFloat3(const std::string& name, float3 value) const {
    glUniform3fv(findUniform(name), 1, &value[0]);
}
void ShaderProgram::setFloat4(const std::string& name, float4 value) const {
    glUniform4fv(findUniform(name), 1, &value[0]);
}


void ShaderProgram::setFloat4x4(const std::string& name, float4x4 value) const {
    glUniformMatrix4fv(findUniform(name), 1, GL_FALSE, &value[0][0]);
}


GLint ShaderProgram::findUniform(const std::string& name) const {
    return glGetUniformLocation(this->ID, name.c_str());
}