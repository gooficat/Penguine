#include "render/shader.h"

ShaderResource::ShaderResource(const std::string& path, const ShaderType& type) :
    Resource(path), type(type) {
}

void ShaderResource::Load() {
    this->ID = glCreateShader(
        (type == VERTEX_SHADER) ? GL_VERTEX_SHADER :
        (type == GEOMETRY_SHADER) ? GL_GEOMETRY_SHADER :
      /*(type == FRAGMENT_SHADER) ?*/ GL_FRAGMENT_SHADER
    );
    std::string content = ::Resource::LoadTextFile(path);
    const char* source = content.c_str();
    glShaderSource(ID, 1, &source, NULL);
}

ShaderResource::~ShaderResource() {

}

GLuint ShaderResource::GetID() {
    return this->ID;
}