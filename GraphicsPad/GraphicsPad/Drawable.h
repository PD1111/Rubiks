#pragma once
#include <gl\glew.h>


class Drawable
{
public:
	Drawable();
	~Drawable();
	virtual void InitGL();
	virtual void paintGL()  {}
	virtual void FinGL();

private:
	GLuint vertexBufferID;
	GLuint indexArrayBufferID;
};

