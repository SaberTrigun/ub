#include "camera.h"

namespace UB
{


Camera::Camera(glm::vec3 cameraPosition) :
    position(cameraPosition),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    worldUp(glm::vec3(0.0f, 1.0f, 0.0f))
{}


glm::vec3 Camera::GetCamPosition() const
{
    return position;
}


glm::vec3 Camera::GetCamDirection() const
{
    return position - front;
}


glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(position, position + front, up);
}



}
