#ifndef CAMERA_H
#define CAMERA_H

#include "global.h"

#include "shader.h"


class Camera {
public:
    Camera(float4x4 projection, float3 position, float3 rotation);
    void use(ShaderProgram& shaderProgram);
    float3 position;
    float3 rotation;

    static float4x4 makePerspective(float fov, float aspect, float clip_near, float clip_far);
    static float4x4 makeOrthographic(float width, float height);
protected:
    void updateViewMatrix();
    void updateProjectionMatrix();
private:
    float4x4 view_matrix;
    float4x4 projection_matrix;
};

#endif