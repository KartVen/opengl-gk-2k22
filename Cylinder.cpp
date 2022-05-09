#include "Cylinder.h"

#define PI 3.14159265

Cylinder::Cylinder(Position pos, Size2 size, Color color, int density, float sectorScale)
{
	this->pos = pos;
	this->size = size;
	this->color = color;
	this->density = density;
	this->sectorScale = sectorScale;
}

Cylinder::Cylinder(Position pos, Size2 size, Color color, char startAxe, int density, float sectorScale) {
	this->pos = pos;
	this->size = size;
	this->startAxe = startAxe;
	this->color = color;
	this->density = density;
	this->sectorScale = sectorScale;
}

void Cylinder::setAxe(char startAxe) {
	this->startAxe = startAxe;
}

void Cylinder::draw()
{
	int trianglesInCircleAmount = density - density % 2;
	float triangleSectorScale = sectorScale;

	if(startAxe == 'x') {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x, pos.y, pos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(pos.x, y + pos.y, z + pos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(pos.x, y + pos.y, z + pos.z);
			glVertex3f(pos.x + size.h, y + pos.y, z + pos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x + size.h, pos.y, pos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(pos.x + size.h, y + pos.y, z + pos.z);
		}
		glEnd();

	}

	else if(startAxe == 'y') {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x, pos.y, pos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, pos.y, z + pos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, pos.y, z + pos.z);
			glVertex3f(x + pos.x, pos.y + size.h, z + pos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x, pos.y + size.h, pos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, pos.y + size.h, z + pos.z);
		}
		glEnd();

	}
	else {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x, pos.y, pos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, y + pos.y, pos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, y + pos.y, pos.z);
			glVertex3f(x + pos.x, y + pos.y, pos.z + size.h);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(pos.x, pos.y, pos.z + size.h);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + pos.x, y + pos.y, pos.z + size.h);
		}
		glEnd();

	}
}
