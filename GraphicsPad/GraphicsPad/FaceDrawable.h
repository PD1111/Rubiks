#pragma once
#include "Drawable.h"
#include <glm\glm.hpp>

class FaceDrawable : public Drawable
{
public:
	FaceDrawable(glm::vec3 point, glm::vec3 direction1, glm::vec3 direction2, glm::vec3 color);
	~FaceDrawable();
	void paintGL() override;
	void updateBasepoint(glm::vec3 point)															{ basePoint = point; }
	void updateBaseDirection(glm::vec3 direction1, glm::vec3 direction2)							{ baseDirection1 = direction1; baseDirection2 = direction2; }
	void updateBaseColor(glm::vec3 color)															{ baseColor = color; }

private:
	glm::vec3 basePoint;
	glm::vec3 baseDirection1;
	glm::vec3 baseDirection2;
	glm::vec3 baseColor;
};

