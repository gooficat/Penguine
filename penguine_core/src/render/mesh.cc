#include "render/mesh.h"


MeshResource::MeshResource(const std::string& path) : Resource(path) {

}

void MeshResource::generateVAO(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    if (!VAO) {
        std::cerr << "VAO is null!" << std::endl;
    }
    if (!VBO) {
        std::cerr << "VBO is null!" << std::endl;
    }
    if (!EBO) {
        std::cerr << "EBO is null!" << std::endl;
    }
    
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glBindVertexArray(0);

    this->num_indices = indices.size();
}

void MeshResource::draw() {
    // std::cout << "I am being rendered" << std::endl;
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}