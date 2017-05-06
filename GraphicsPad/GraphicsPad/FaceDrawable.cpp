#include "FaceDrawable.h"
#include <Vertex.h>



FaceDrawable::FaceDrawable(glm::vec3 point, glm::vec3 direction1, glm::vec3 direction2, glm::vec3 color) :
	basePoint(point),
	baseDirection1(direction1),
	baseDirection2(direction2),
	baseColor(color)
{
	Drawable::Drawable();
}


FaceDrawable::~FaceDrawable()
{
}

void FaceDrawable::paintGL()
{
	Vertex faces[] =
	{
		basePoint,
		baseColor,

		glm::vec3(basePoint.x + baseDirection1.x * 0.45, basePoint.y + baseDirection1.y * 0.45, basePoint.z + baseDirection1.z * 0.45),
		baseColor,

		glm::vec3(basePoint.x + baseDirection2.x * 0.45, basePoint.y + baseDirection2.y * 0.45, basePoint.z + baseDirection2.z * 0.45),
		baseColor,

		glm::vec3(basePoint.x + baseDirection1.x * 0.45 + baseDirection2.x * 0.45,
				  basePoint.y + baseDirection1.y * 0.45 + baseDirection2.y * 0.45,
				  basePoint.z + baseDirection1.z * 0.45 + baseDirection2.z * 0.45),
		baseColor,
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(faces), faces, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));


	GLushort indices[] = { 0, 1, 2, 1, 2, 3 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}
