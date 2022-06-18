#include "App.h"
#include <iostream>
#include "Textures.h"

App::App()
{
	events = Events::getEvents();
	Textures::initTextures();

	camera = Camera::getCamera();
	camera->setFOV(CAM_FOV);
	camera->setSensivity(CAM_SENSIVITY_X, CAM_SENSIVITY_Y);
	camera->setYLock(CAM_Y_LOCK);
	camera->setYBorder(CAM_Y_BORDER);

	terrain = new Terrain();
	combineRobot = new CombineRobot(.65, {0,0,0});
}

App::~App()
{
	Camera::destroyCamera();
	Textures::destroyTextures();
}

void App::update()
{
	switch (events->basicKey.key) {
	case 27:
		if (events->basicKey.state == events->keyDown) exit(0);
		break;
	}

	combineRobot->update();

	camera->pos = combineRobot->pos * combineRobot->scale;
	camera->update();
}

void App::render()
{
	terrain->render();
	combineRobot->render();
}