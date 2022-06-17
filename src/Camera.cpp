#include "Camera.h"
#include <iostream>

Camera* Camera::selfInstance = nullptr;

Camera::Camera()
{
	fov = 5.;
	deltaAngle = { 0.,0. };
	deltaMove = .0;
	pos = { .0,.0,.0 };
	sensivity = { .05,.03 };
	origin = 0;
	yBorder = 0;
	yLock = false;
	
	cameraMoving = false;
	updateDir(0,0);
	events = Events::getEvents();
}

Camera::~Camera() = default;

Camera* Camera::getCamera()
{
	if (selfInstance == nullptr) selfInstance = new Camera();
	return selfInstance;
}

void Camera::destroyCamera()
{
	delete selfInstance;
	selfInstance = nullptr;
}

void Camera::update()
{
	double bp = deltaAngle.x;
	switch (events->basicKey.key) {
	case 'q':
		if(events->basicKey.state == GLUT_UP)
			deltaMove = 0;
		else if (events->basicKey.state == GLUT_DOWN)
			deltaMove = .5;
		break;
	case 'e':
		if (events->basicKey.state == GLUT_UP)
			deltaMove = 0;
		else if (events->basicKey.state == GLUT_DOWN)
			deltaMove = -.5;
		break;
	}

	switch (events->mouseKey.key)
	{
	case GLUT_LEFT_BUTTON:
		if (events->mouseKey.state == GLUT_UP) {
				angle.x += deltaAngle.x;
				angle.y += deltaAngle.y;
				deltaAngle = 0;
			cameraMoving = false;
		}
		else if (events->mouseKey.state == GLUT_DOWN){
			origin.x = events->mouseKey.cursor.x;
			origin.y = events->mouseKey.cursor.y;
			cameraMoving = true;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		break;
	}
	
	if (cameraMoving) {

		if (events->mousePos.y < 0) events->mousePos.y = 0;
		if (events->mousePos.y > HEIGHT) events->mousePos.y = HEIGHT;

		if (events->mousePos.x < 0) events->mousePos.x = 0;
		if (events->mousePos.x > WIDTH) events->mousePos.x = WIDTH;

		updateDir(events->mousePos.x, events->mousePos.y);
	}

	/*if (deltaMove) {
		pos.x += deltaMove * 10e-3;
		pos.z += deltaMove * 10e-3;
	}*/
}

void Camera::setFOV(int fov)
{
	this->fov = fov;
	updateDir(0, 0);
}

void Camera::setSensivity(double senvX, double senvY)
{
	if (senvX < 0) senvX = -senvX;
	if (senvY < 0) senvY = -senvY;
	this->sensivity = { senvX, senvY };
	updateDir(0, 0);
}

void Camera::setYBorder(double yBorder)
{
	this->yBorder = yBorder;
}

void Camera::setYLock(bool lock)
{
	yLock = lock;
}

void Camera::updateDir(int x, int y)
{
	// update camera's direction
	deltaAngle.x = (x - origin.x) * sensivity.x;
	deltaAngle.y = (y - origin.y) * sensivity.y;

	double alphaX = angle.x + deltaAngle.x;
	double alphaY = angle.y + deltaAngle.y;

	if (yLock) {
		if (alphaY < yBorder) alphaY = yBorder;
		const double Y_MAX_BORDER = M_PI_2 - 0.25;
		if (alphaY > Y_MAX_BORDER) alphaY = Y_MAX_BORDER;
	}

	dir.x = cos(alphaY) * cos(alphaX) * fov;
	dir.y = sin(alphaY) * fov;
	dir.z = cos(alphaY) * sin(alphaX) * fov;
}

void Camera::renderLookAxe(bool x, bool y, bool z)
{
	if (x) {
		// xAxis
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3d(0, 0, 0);
		glVertex3d(100, 0, 0);
		glEnd();
	}
	if (y) {
		// yAxis
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 100, 0);
		glEnd();
	}
	if (z) {
		// zAxis
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 100);
		glEnd();
	}
}

void Camera::renderLookAt()
{
	gluLookAt(
		pos.x + dir.x,
		pos.y + dir.y,
		pos.z + dir.z,
		pos.x,
		pos.y,
		pos.z,
		0.0f,
		1.0f,
		0.0f
	);
}
