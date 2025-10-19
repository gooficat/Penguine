#include "render/camera.h"


Camera::Camera(float4x4 projection, float3 position = {0,0,0}, float3 rotation = {0,0,0}) :
    projection_matrix(projection), position(position), rotation(rotation) {
    
}

void Camera::use(ShaderProgram& shaderProgram) {
    this->updateViewMatrix();
}

void Camera::updateViewMatrix() {

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