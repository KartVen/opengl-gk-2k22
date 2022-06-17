#include "Events.h"

Events* Events::selfInstance = nullptr;

Events::Events() {
	mousePos = { -1,-1 };
};

void Events::initEvents()
{
	if (selfInstance == nullptr) selfInstance = new Events();
}

Events* Events::getEvents()
{
	return selfInstance;
}

void Events::destroyEvents()
{
	delete selfInstance;
	selfInstance = nullptr;
}

void Events::reset()
{
	basicKey.state = -1;
	specialKey.state = -1;
	mouseKey.state = -1;
	basicKey.key = -1;
	specialKey.key = -1;
	mouseKey.key = -1;
}
