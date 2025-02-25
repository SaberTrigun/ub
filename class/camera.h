#ifndef UB_CAMERA_H
#define UB_CAMERA_H


#include <cmath>
#include "gameActor.h"


namespace UB
{


class Camera : public GameActor
{
public:
    Camera();
    Camera(glm::vec3 cameraPosition);

    glm::vec3 getPosition() const override;

    void setPosition(glm::vec3& position) override;

    void moveForward(float deltaTime) override;

    void moveBackward(float deltaTime) override;

    void moveLeft(float deltaTime) override;

    void moveRight(float deltaTime) override;

    glm::mat4 getViewMatrix() const;

private:
    void updateCameraVectors();

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    glm::vec3 worldUp;
    glm::vec3 right;

    float movementSpeed;

};

}


#endif // UB_CAMERA_H
