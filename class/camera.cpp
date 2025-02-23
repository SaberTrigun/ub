#include "camera.h"

namespace UB
{


Camera::Camera(){}


Camera::Camera(glm::vec3 cameraPosition) :
    position(cameraPosition),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    direction(position - front)
{}
//Camera::Camera(glm::vec3 cameraPosition) :
//    position(cameraPosition),
//    front(glm::vec3(0.0f, 0.0f, -1.0f)),
//    worldUp(glm::vec3(0.0f, 1.0f, 0.0f))
//{}


glm::vec3 Camera::getPosition() const
{
    return position;
}


void Camera::setPosition(glm::vec3& position)
{
}


void Camera::moving()
{

}


glm::vec3 Camera::getDirection() const
{
    return direction;
}


glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(position, direction, up);
}



}
