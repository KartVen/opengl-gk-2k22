#include "CombineRobot.h"
#include <iostream>
#include "DEFINES.H"

CombineRobot::CombineRobot(double scale, Vec3 pos) {
	events = Events::getEvents();
	this->pos = pos;
	rotate = { 0,0,0 };
	self = new Model("assets/vehicle/", "car.obj", scale, pos);
	size = { 0,0,0 };
}

CombineRobot::~CombineRobot() {
	delete self;
}

bool driveUp, driveDown;
bool turnLeft, turnRight;
bool aC = 0, bC = 0, cC = 0, dC = 0;

void CombineRobot::update(){

	switch (events->basicKey.key) {
	case 'w':
		if (events->basicKey.state == events->keyDown) {
			driveUp = 1;
		}
		else if (events->basicKey.state == events->keyUp) {
			driveUp = 0;
		}
		break;
	case 's':
		if (events->basicKey.state == events->keyDown) {
			driveDown = 1;
		}
		else if (events->basicKey.state == events->keyUp) {
			driveDown = 0;
		}
		break;
	case 'a':
		if (events->basicKey.state == events->keyDown) {
			turnLeft = 1;
		}
		else if (events->basicKey.state == events->keyUp) {
			turnLeft = 0;
		}
		break;
	case 'd':
		if (events->basicKey.state == events->keyDown) {
			turnRight = 1;
		}
		else if (events->basicKey.state == events->keyUp) {
			turnRight = 0;
		}
		break;
	}

	if (driveUp && !driveDown) drive(2);
	if (!driveUp && driveDown) drive(-2);
	if (turnLeft && !turnRight) turn(-2);
	if (!turnLeft && turnRight) turn(2);
	//std::cout << rotate.y << '\n';
	self->pos = pos;
}

void CombineRobot::render() {
	self->renderAxe(1, 0, 1);
	glPushMatrix();

	glTranslated(posBB.x,posBB.y,posBB.z);
	glPushMatrix();
	glRotated(-rotate.y, 0, 1, 0);

	

	//Vec3 shiftPos = pos - posBB;
	//glTranslated(shiftPos.x, shiftPos.y, shiftPos.z);
	glTranslated(pos.x, pos.y, pos.z);

	glPopMatrix();
	
	glTranslated(-pos.x, -pos.y, -pos.z);

	self->render();
	
	glPopMatrix();
}

void CombineRobot::drive(double v) {
	posBB = pos;
	pos.x += v;
}

void CombineRobot::turn(double v) {
	rotate.y += v;

	rotate.y = rotate.y >= 360 ? rotate.y - 360 : rotate.y;
	rotate.y = rotate.y <= 360 ? rotate.y + 360 : rotate.y;
}