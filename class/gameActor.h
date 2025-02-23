#ifndef __GAMEACTOR_H__
#define __GAMEACTOR_H__


#include "../include/glm/glm/glm.hpp"
#include "../include/glm/glm/gtc/matrix_transform.hpp"
#include "../include/glm/glm/gtc/type_ptr.hpp"


namespace UB
{


class GameActor
{
public:
	virtual void moveUp(float deltaTime) = 0;
	virtual glm::vec3  getPosition() const = 0;
	virtual void setPosition(glm::vec3& position) = 0;
	// virtual void getSize() = 0;
	// virtual void setSize(Size) = 0;

};
}




#endif
