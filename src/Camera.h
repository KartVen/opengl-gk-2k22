#pragma once
#include "DEFINES.h"
#include "Base.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Events.h"

class Camera
{
public:
	// camera - Vec3
	Vec3 pos;
	// camera direction - vector
	Vec3 dir;
private:
	Vec2 angle;
	Vec2 deltaAngle;
public:
	float deltaMove;
private:
	Vec2 origin;
	Vec2 sensivity;
	int fov;
public:
	bool cameraMoving;
private:
	Events* events;
public:
	Camera();
	~Camera();
	void update();
	void setFOV(int fov);
	void setSensivity(double senvX, double senvY);
	void updateDir(int x, int y);
	void renderLookAxe();
};

