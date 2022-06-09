#pragma once
#include "Base.h"
#include "Model.h"
#include "Events.h"

class Terrain
{
	Events* events;
	Model* ground;
	Vec3 basePos;
	
	Model* house;
	std::vector<Model*> trees;
	std::vector<Model*> fences1;
	std::vector<Model*> fences2;
	std::vector<Model*> fences3;
	std::vector<Model*> fences4;
public:
	Terrain();
	~Terrain();
	void update();
	void render();
};

