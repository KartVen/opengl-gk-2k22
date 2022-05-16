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

void Cylinder::draw(Position pos)
{
	Position drawPos = this->pos + pos;
	int trianglesInCircleAmount = density - density % 2;
	float triangleSectorScale = sectorScale;

	if(startAxe == 'x') {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x, drawPos.y, drawPos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(drawPos.x, y + drawPos.y, z + drawPos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(drawPos.x, y + drawPos.y, z + drawPos.z);
			glVertex3f(drawPos.x + size.h, y + drawPos.y, z + drawPos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x + size.h, drawPos.y, drawPos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double y = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(drawPos.x + size.h, y + drawPos.y, z + drawPos.z);
		}
		glEnd();

	}

	else if(startAxe == 'y') {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x, drawPos.y, drawPos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, drawPos.y, z + drawPos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, drawPos.y, z + drawPos.z);
			glVertex3f(x + drawPos.x, drawPos.y + size.h, z + drawPos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x, drawPos.y + size.h, drawPos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double z = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, drawPos.y + size.h, z + drawPos.z);
		}
		glEnd();

	}
	else {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x, drawPos.y, drawPos.z);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, y + drawPos.y, drawPos.z);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(color.r, color.g, color.b);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, y + drawPos.y, drawPos.z);
			glVertex3f(x + drawPos.x, y + drawPos.y, drawPos.z + size.h);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color.r, color.g, color.b);
		glVertex3f(drawPos.x, drawPos.y, drawPos.z + size.h);
		for (double i = 0; i <= triangleSectorScale * trianglesInCircleAmount; ++i)
		{
			double x = size.r * sin(i * (PI * 2) / trianglesInCircleAmount);
			double y = size.r * cos(i * (PI * 2) / trianglesInCircleAmount);
			glVertex3f(x + drawPos.x, y + drawPos.y, drawPos.z + size.h);
		}
		glEnd();

	}
}
