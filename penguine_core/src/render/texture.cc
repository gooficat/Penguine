#include "render/texture.h"

Texture::Texture(const string& path) : Resource(path) {

}

Texture::~Texture() {
    
}

void Texture::load() {
    int width, height, nr_channels;

    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nr_channels, 0);

    if (!data) {
        std::cerr << "failed to load texture " << path << std::endl;
        return;
    }
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}