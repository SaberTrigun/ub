#ifndef UB_CAMERA_H
#define UB_CAMERA_H


#include <cmath>
#include "../include/glm/glm/glm.hpp"
#include "../include/glm/glm/gtc/matrix_transform.hpp"
#include "../include/glm/glm/gtc/type_ptr.hpp"

namespace UB
{


class Camera
{
public:
    Camera(glm::vec3 cameraPosition);

    glm::vec3 GetCamPosition() const;

    glm::vec3 GetCamDirection() const;

    glm::mat4 GetViewMatrix() const;

private:
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    glm::vec3 front;
    glm::vec3 position;
};

}


#endif // UB_CAMERA_H
