#include "Scene.h"
#include "FaceDrawable.h"


Scene::Scene()
{
	InitCubeFace();
}


Scene::~Scene()
{
}

void Scene::drawGL()
{
	//drawSingleFace(topFace);
	//drawSingleFace(bottomFace);
	//drawSingleFace(rightFace);
	//drawSingleFace(leftFace);
	drawSingleFace(frontFace);
	//drawSingleFace(backFace);
}

void Scene::InitGL()
{
	InitSingleFace(topFace);
	InitSingleFace(bottomFace);
	InitSingleFace(rightFace);
	InitSingleFace(leftFace);
	InitSingleFace(frontFace);
	InitSingleFace(backFace);
}

void Scene::FinGL()
{
	FinSingleFace(topFace);
	FinSingleFace(bottomFace);
	FinSingleFace(leftFace);
	FinSingleFace(rightFace);
	FinSingleFace(frontFace);
	FinSingleFace(backFace);
}

void Scene::InitCubeFace()
{
	double offset = 0.6666;

	//create top face
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			topFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(-1.0 + j * offset, 1, 1 - i * offset), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 0, 0)));
		}
	}

	//create bottom face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bottomFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(-1.0 + j * offset, -1, 1 - i * offset), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1), glm::vec3(1, 1, 0)));
		}
	}

	//create left face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			leftFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(-1.0, 1 - i * offset, 1 - j * offset), glm::vec3(0, -1, 0), glm::vec3(0, 0, 1), glm::vec3(1, 0, 0)));
		}
	}

	//create right face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rightFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(1.0, 1 - i * offset, 1 - j * offset), glm::vec3(0, -1, 0), glm::vec3(0, 0, 1), glm::vec3(1, 0.647, 0)));
		}
	}

	//create front face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			frontFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(-1.0 + j * offset, 1 - i * offset, -1), glm::vec3(1, 0, 0), glm::vec3(0, -1, 0), glm::vec3(0, 0, 1)));
		}
	}

	//create back face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			backFace.push_back(std::make_shared<FaceDrawable>(glm::vec3(-1.0 + j * offset, 1 - i * offset, 1), glm::vec3(1, 0, 0), glm::vec3(0, -1, 0), glm::vec3(0, 1, 0)));
		}
	}
}

void Scene::drawSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face)
{
	for (std::shared_ptr<FaceDrawable> drawable : face)
	{
		drawable->paintGL();
	}
}

void Scene::InitSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face)
{
	for (std::shared_ptr<FaceDrawable> drawable : face)
	{
		drawable->InitGL();
	}
}

void Scene::FinSingleFace(std::vector<std::shared_ptr<FaceDrawable>> face)
{
	for (std::shared_ptr<FaceDrawable> drawable : face)
	{
		drawable->FinGL();
	}
}
