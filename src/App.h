#pragma once
#include <gl\glut.h>
#include "DEFINES.h"
#include "Events.h"
#include "Camera.h"
#include "CombineRobot.h"
#include "Terrain.h"

class App
{
private:
	Events* events;
	CombineRobot* combineRobot;
	Terrain* terrain;
public:
	Camera* camera;
public:
	App();
	~App();
	void update();
	void render();
};

