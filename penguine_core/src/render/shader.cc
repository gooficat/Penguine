#include "render/shader.h"

ShaderResource::ShaderResource(const std::string& path, const ShaderType& type) {
    this->ID = glCreateShader(
        (type == VERTEX_SHADER) ? GL_VERTEX_SHADER :
        (type == GEOMETRY_SHADER) ? GL_GEOMETRY_SHADER :
      /*(type == FRAGMENT_SHADER) ?*/ GL_FRAGMENT_SHADER
    );
    std::string content = Resource::LoadTextFile(path);
    
}

void ShaderResource::Load() {

}

ShaderResource::~ShaderResource() {

}

GLuint ShaderResource::GetID() {
    return this->ID;
}