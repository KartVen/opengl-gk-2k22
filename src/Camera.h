#pragma once
#include "DEFINES.h"
#include "Base.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Events.h"

class Camera
{
private:
	static Camera* selfInstance;
public:
	// camera - Vec3
	Vec3 pos;
	// camera direction - vector
	Vec3 dir;
private:
	Vec2 angle;
public:
	Vec2 deltaAngle;
	float deltaMove;
	double yBorder;
	bool yLock;
private:
	Vec2 origin;
	Vec2 sensivity;
	int fov;
public:
	bool cameraMoving;
private:
	Events* events;
	Camera();
	~Camera();
public:
	static Camera* getCamera();
	static void destroyCamera();
	void update();
	void setFOV(int fov);
	void setSensivity(double senvX, double senvY);
	void setYBorder(double yBorder);
	void setYLock(bool lock = true);
	void updateDir(int x, int y);
	void renderLookAxe(bool x, bool y, bool z);
	void renderLookAt();
};

