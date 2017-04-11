#pragma once
#include "Drawable.h"
#include <glm\glm.hpp>

class FaceDrawable : public Drawable
{
public:
	FaceDrawable(glm::vec3 point, glm::vec3 direction1, glm::vec3 direction2, glm::vec3 color);
	~FaceDrawable();
	void paintGL() override;

private:
	glm::vec3 basePoint;
	glm::vec3 baseDirection1;
	glm::vec3 baseDirection2;
	glm::vec3 baseColor;
};

