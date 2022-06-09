#include "App.h"
#include <iostream>
#include "TexturesData.h"

App::App()
{
	events = Events::getEvents();
	TexturesData::init();
	
	camera = new Camera();
	camera->setFOV(CAM_FOV);
	camera->setSensivity(CAM_SENSIVITY_X, CAM_SENSIVITY_Y);

	terrain = new Terrain();
	combineRobot = new CombineRobot(0.005);
}

App::~App()
{
	delete camera;
	TexturesData::destroy();
}

void App::update()
{
	switch (events->basicKey.key) {
	case 27:
		if (events->basicKey.state == events->down) exit(0);
		break;
	}

	combineRobot->update();

	//camera->pos = combineRobot->absolutePos;
	camera->update();
}

void App::render()
{
	terrain->render();
	combineRobot->render();
}
