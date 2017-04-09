#include "Camera.h"
#include <glm\gtx\transform.hpp>



Camera::Camera() :
	viewDirection(0.0f, 0.0f, -1.0f),
	UP(0.0f, 1.0f, 0.0f)
{
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, UP);
}


Camera::~Camera()
{
}

void Camera::mouseUpdate(const glm::vec2 & newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
	if ( glm::length(mouseDelta) <= 30.0f) 
	{
		viewDirection = glm::mat3(glm::rotate(-mouseDelta.x, UP)) * viewDirection;
	}

	glm::vec3 toRotateAround = glm::cross(viewDirection, UP);
	viewDirection = glm::mat3(glm::rotate(-mouseDelta.y, toRotateAround)) * viewDirection;
	oldMousePosition = newMousePosition;
}

void Camera::moveForward()
{
	position += movementSpeed * viewDirection;
}

void Camera::moveBackward()
{
	position -= movementSpeed * viewDirection;
}

void Camera::moveLeft()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position += movementSpeed * strafeDirection;
}

void Camera::moveRight()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position -= movementSpeed * strafeDirection;
}

void Camera::moveUp()
{
	position += movementSpeed * UP;
}

void Camera::moveDown()
{
	position -= movementSpeed * UP;
}
