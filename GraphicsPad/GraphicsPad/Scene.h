#pragma once
#include <memory>
#include <vector>
#include "Camera.h"

class FaceDrawable;

class Scene
{
public:
	Scene(int ID);
	~Scene();
	void drawGL();
	void InitGL();
	void FinGL();
	void UpdateWindowSize(float w, float h)			{ height = h; width = w; }
	void UpdateMousePos(float x, float y)			{ viewpoint->mouseUpdate(glm::vec2(x, y)); }

private:
	void InitCubeFace();
	void InitCubeWorldPosition();
	void drawSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face);
	void InitSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face);
	void FinSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face);

private:
	 std::vector<std::shared_ptr<FaceDrawable>> topFace;
	 std::vector<std::shared_ptr<FaceDrawable>> bottomFace;
	 std::vector<std::shared_ptr<FaceDrawable>> leftFace;
	 std::vector<std::shared_ptr<FaceDrawable>> rightFace;
	 std::vector<std::shared_ptr<FaceDrawable>> frontFace;
	 std::vector<std::shared_ptr<FaceDrawable>> backFace;
	 float	height;
	 float	width;
	 int programID;
	 Camera* viewpoint;
};

