#include "CombineRobot.h"
#include <iostream>
#include "DEFINES.H"
#define _USE_MATH_DEFINES
#include <math.h>

CombineRobot::CombineRobot(double scale, Vec3 pos) {
	events = Events::getEvents();
	this->pos = pos;
	rotate = { 0,0,0 };
	self = new Model("assets/combine-obj/body/", "combine-body.obj", scale, pos);

	std::string combineAssetsPath = "assets/combine-obj/";

	double scaleWheel = self->scale;

	leftFrontWheel = new Wheel2(combineAssetsPath + "WheelFrontLeft/", "WheelFrontLeft.obj", scaleWheel, { 0,0,0 });
	rightFrontWheel = new Wheel2(combineAssetsPath + "WheelFrontRight/", "WheelFrontRight.obj", scaleWheel, { 0,0,0 });
	leftBackWheel = new Wheel2(combineAssetsPath + "WheelRearLeft/", "WheelRearLeft.obj", scaleWheel, { 0,0,0 });
	rightBackWheel = new Wheel2(combineAssetsPath + "WheelRearRight/", "WheelRearRight.obj", scaleWheel, { 0,0,0 });

	leftBackWheel->setModelAxePos({ -1.2569,0,3.5 });
	rightBackWheel->setModelAxePos({ 1.2569,0,3.5 });

	size = { 0,0,0 };
	speed = 0;
	facing = { 0,0,1 };
	wheelAngle = 0;
	this->scale = scale;
}

CombineRobot::~CombineRobot() {
	delete leftBackWheel;
	delete rightBackWheel;
	delete leftBackWheel;
	delete rightBackWheel;
	delete self;
}

bool driveUp = 0, driveDown = 0;
bool turnLeft = 0, turnRight = 0;
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

	if (driveUp && !driveDown) drive(0.175);
	if (!driveUp && driveDown) drive(-0.175);
	if (turnLeft && !turnRight) turn(-1);
	if (!turnLeft && turnRight) turn(1);

	updatePhysics();
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
	
	//self->renderAxe(1, 1, 1);
	
	glPushMatrix();

	glTranslated(pos.x * self->scale, pos.y * self->scale, pos.z * self->scale);
	glRotated(rotate.y, 0, 1, 0);

	self->render();
	leftFrontWheel->render();
	rightFrontWheel->render();

	glPushMatrix();

	glTranslated(1.2569 * self->scale, 0 * self->scale, -3.5 * self->scale);
	glRotated(wheelAngle, 0, 1, 0);
	leftBackWheel->render();
	
	glPopMatrix();
	glPushMatrix();

	glTranslated(-1.2569 * self->scale, 0 * self->scale, -3.5 * self->scale);
	glRotated(wheelAngle, 0, 1, 0);
	rightBackWheel->render();
	
	glPopMatrix();
	glPopMatrix();
}

void CombineRobot::drive(double v) {
	speed += v;
	double maxSpeed = .35;
	if (speed > maxSpeed) speed = maxSpeed;
	if (speed < -maxSpeed) speed = -maxSpeed;
}

void CombineRobot::turn(double v) {
	wheelAngle += v;
	if (wheelAngle > 30) wheelAngle = 30;
	if (wheelAngle < -30) wheelAngle = -30;
}

void CombineRobot::updatePhysics()
{
	posBB = pos;
	pos = {
		pos.x + speed * facing.x,
		pos.y,
		pos.z + speed * facing.z,
	};

	double friction = .025;

	if (speed > 0) speed -= friction;
	if (speed < 0) speed += friction;
	if (speed < friction && speed > -friction) speed = 0;

	rotate.y += 1. * speed * (-wheelAngle);
	
	if (rotate.y > 360); rotate.y -= 360;
	if (rotate.y < -360); rotate.y += 360;

	facing.x = sin(rotate.y * M_PI / 180);
	facing.z = cos(rotate.y * M_PI / 180);
}
