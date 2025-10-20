#pragma once

#include "global.h"

#include "resource.h"

struct Vertex {
    float3 position;
    float2 tex_coord;
    float2 normal;
};

class MeshResource : public Resource {
public:
    MeshResource(const std::string& path);

    void draw();
    void generateVAO(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
private:
    GLuint VAO;
    GLuint VBO, EBO;
    size_t num_indices;
};