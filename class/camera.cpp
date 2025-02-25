#include "camera.h"

namespace UB
{


Camera::Camera(){}


Camera::Camera(glm::vec3 cameraPosition) :
    position(cameraPosition),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    worldUp(up)
{
    updateCameraVectors();
}
//Camera::Camera(glm::vec3 cameraPosition) :
//    position(cameraPosition),
//    front(glm::vec3(0.0f, 0.0f, -1.0f)),
//    worldUp(glm::vec3(0.0f, 1.0f, 0.0f))
//{}


void Camera::updateCameraVectors()
{
    glm::vec3 newFront;

    newFront.x = cos(glm::radians(-90.0f)) * cos(glm::radians(0.0f));
    newFront.y = sin(glm::radians(0.0f));
    newFront.z = sin(glm::radians(-90.0f)) * cos(glm::radians(0.0f));

    front = glm::normalize(newFront);

    right = glm::normalize(glm::cross(front, worldUp));
    up    = glm::normalize(glm::cross(right, front));
}


glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(position, position + front, up);
}


glm::vec3 Camera::getPosition() const
{
    return position;
}


void Camera::setPosition(glm::vec3& position)
{
}


void Camera::moveForward(float deltaTime)
{
    float velocity = 2.5f * deltaTime;
    position += front * velocity;
}


void Camera::moveBackward(float deltaTime)
{
    float velocity = 2.5f * deltaTime;
    position -= front * velocity;
}


void Camera::moveLeft(float deltaTime)
{
    float velocity = 2.5f * deltaTime;
    position -= right * velocity;
}


void Camera::moveRight(float deltaTime)
{
    float velocity = 2.5f * deltaTime;
    position += right * velocity;

}



}
