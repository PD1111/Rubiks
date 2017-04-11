#include "Drawable.h"

Drawable::Drawable()
{
	vertexBufferID = 0;
	indexArrayBufferID = 0;
}


Drawable::~Drawable()
{
}

void Drawable::InitGL()
{
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glGenBuffers(1, &indexArrayBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
}

void Drawable::FinGL()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
