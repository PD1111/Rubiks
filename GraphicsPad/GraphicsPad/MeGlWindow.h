#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#pragma once
#include <QtOpenGL\QGLWidget>
using namespace std;

class MeGlWindow : public QGLWidget
{
public:
	bool checkShaderStatus(GLuint shaderID);
	bool checkProgramStatus(GLuint programID);
	void sendDatatoOpenGL();
	string readShaderCode(const char* fileName);
	void installShaders();
protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);

public:
	~MeGlWindow();
};

#endif

