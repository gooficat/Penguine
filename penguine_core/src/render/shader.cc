#include "render/shader.h"

ShaderResource::ShaderResource(const string& path, const ShaderType& type) :
    Resource(path), type(type) {
}

void ShaderResource::load() {
    GLenum shader_type;
    switch (type) {
        case VERTEX_SHADER:
            shader_type = GL_VERTEX_SHADER;
            break;
        case FRAGMENT_SHADER:
            shader_type = GL_FRAGMENT_SHADER;
            break;
        case GEOMETRY_SHADER:
            shader_type = GL_GEOMETRY_SHADER;
            break;
        default:
            std::cerr << "currently we only support vertex, geometry and fragment shaders!" << std::endl;
            break;
    }
    this->ID = glCreateShader( // i am so infuriated right now. i switched to glfw from rgfw for WHAT
        shader_type
    );
    string content = ::Resource::loadTextFile(path);
    const char* source = content.c_str();
    glShaderSource(ID, 1, &source, NULL);
    glCompileShader(ID);
}

ShaderResource::~ShaderResource() {
    glDeleteShader(this->ID);
}

GLuint ShaderResource::getID() const {
    return this->ID;
}

ShaderProgram::ShaderProgram(const ShaderResource& vertex_shader, const ShaderResource& fragment_shader) {
    this->ID = glCreateProgram();
    glUseProgram(this->ID);

    glAttachShader(this->ID, vertex_shader.getID());
    glAttachShader(this->ID, fragment_shader.getID());

    glLinkProgram(this->ID);
}

void ShaderProgram::use() const {
    glUseProgram(this->ID);
}


void ShaderProgram::setInt(const string& name, GLint value) const {
    glUniform1i(findUniform(name), value);
}

void ShaderProgram::setFloat(const string& name, GLfloat value) const {
    glUniform1f(findUniform(name), value);
}
void ShaderProgram::setFloat2(const string& name, float2 value) const {
    glUniform2fv(findUniform(name), 1, &value[0]);
}
void ShaderProgram::setFloat3(const string& name, float3 value) const {
    glUniform3fv(findUniform(name), 1, &value[0]);
}
void ShaderProgram::setFloat4(const string& name, float4 value) const {
    glUniform4fv(findUniform(name), 1, &value[0]);
}


void ShaderProgram::setFloat4x4(const string& name, float4x4 value) const {
    glUniformMatrix4fv(findUniform(name), 1, GL_FALSE, &value[0][0]);
}


GLint ShaderProgram::findUniform(const string& name) const {
    return glGetUniformLocation(this->ID, name.c_str());
}