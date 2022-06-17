#include "Wheel2.h"

Wheel2::Wheel2(std::string folderPath, std::string fileName, double scale, Vec3 pos)
{
	events = Events::getEvents();
	this->pos = pos;
	rotate = { 0,0,0 };
	self = new Model(folderPath, fileName, scale, pos);
	size = { 0,0,0 };
}

Wheel2::~Wheel2()
{
	delete self;
}

void Wheel2::update()
{
}

void Wheel2::render()
{
	self->render();
}

void Wheel2::setModelAxePos(Vec3 modelAxePos)
{
	self->modelAxePos = modelAxePos;
}

void Wheel2::drive(double v)
{
}

void Wheel2::turn(double v)
{
}
