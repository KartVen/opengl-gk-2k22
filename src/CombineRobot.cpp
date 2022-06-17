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
}

void renderAxe(bool x, bool y, bool z) {
	if (x) {
		// xAxis
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3d(0, 0, 0);
		glVertex3d(5000, 0, 0);
		glEnd();
	}
	if (y) {
		// yAxis
		glBegin(GL_LINES);
		glColor3f(0.86f, 0.86f, 0.86f);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 5000, 0);
		glEnd();
	}
	if (z) {
		// zAxis
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 5000);
		glEnd();
	}
}


void CombineRobot::render() {
	self->renderAxe(1, 0, 1);
	
	glPushMatrix();

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