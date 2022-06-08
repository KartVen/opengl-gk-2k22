#pragma once
#include "Base.h"
#include "Model.h"
#include "Events.h"

class Terrain
{
	Events* events;
	Model* ground;
	Vec3 basePos;
	
	std::vector<Model*> trees;
public:
	Terrain();
	~Terrain();
	void update();
	void render();
};

