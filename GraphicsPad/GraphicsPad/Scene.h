#pragma once
#include <memory>
#include <vector>

class FaceDrawable;

class Scene
{
public:
	Scene();
	~Scene();
	void drawGL();
	void InitGL();
	void FinGL();

private:
	void InitCubeFace();
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
};

