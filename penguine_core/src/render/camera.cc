#include "render/camera.h"


Camera::Camera(float4x4 projection, float3 position = {0,0,0}, float3 rotation = {0,0,0}) :
    projection_matrix(projection), position(position), rotation(rotation) {
    // this->updateProjectionMatrix(); still redundant for now
}

void Camera::use(ShaderProgram& shader_program) {
    this->updateViewMatrix();
    shader_program.setFloat4x4("projection", projection_matrix);
    shader_program.setFloat4x4("view", view_matrix);
}

void Camera::updateViewMatrix() {
    view_matrix = linalg::lookat_matrix((float3){0.0f, 0.0f, 3.0f}, (float3){0.0f,0.0f,0.0f}, (float3){0.0f,1.0f,0.0f});
}

void Camera::updateProjectionMatrix() {
    
}



float4x4 Camera::makePerspective(float fov, float aspect, float clip_near, float clip_far) {
    return linalg::perspective_matrix(fov, aspect, clip_near, clip_far);
}

float4x4 Camera::makeOrthographic(float width, float height) {
    float3 scaling = {(float)width/2.0f, (float)height/2.0f, 1.0f};
    return linalg::scaling_matrix(
        scaling
    );
}