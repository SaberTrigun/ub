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

    void moveUp(float deltaTime) override;

    glm::vec3 getDirection() const;

    glm::mat4 getViewMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    glm::vec3 direction;
    //glm::vec3 right;
    //glm::vec3 worldUp;
};

}


#endif // UB_CAMERA_H
