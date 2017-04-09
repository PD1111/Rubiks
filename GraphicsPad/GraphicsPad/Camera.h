#pragma once
#include <glm\glm.hpp>

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 viewDirection;
	const glm::vec3 UP;
	glm::vec2 oldMousePosition;
	const float movementSpeed = 0.1f;

public:
	Camera();
	glm::mat4 getWorldToViewMatrix() const;
	~Camera();
	void mouseUpdate(const glm::vec2& newMousePosition);
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};

