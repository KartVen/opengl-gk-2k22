#include "Cuboid.h"

Cuboid::Cuboid(Position pos, Size size, Color color, bool center){
	this->pos = pos;
	this->rotation = { 0,pos.x,pos.y,pos.z };
	this->size = size;
	this->color = color;
	this->center = center;
}


void Cuboid::draw(Position pos) {
	Position drawPos = this->pos + pos;
	if (center) drawPos = { drawPos.x - size.x / 2, drawPos.y - size.y / 2 , drawPos.z - size.z / 2 };
	int layerDensityScale = 2;
	int doubleTrianglesDensityScale = 10;

	// XZ walls
	double layerWidth = size.x / layerDensityScale;
	double axisStep = size.z / doubleTrianglesDensityScale;

	for (double y = 0; y <= size.y; y += size.y) {
		for (double x = 0; x < layerDensityScale; ++x) {
			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(color.r, color.g, color.b);
			for (double z = 0; z <= doubleTrianglesDensityScale; ++z) {
				glVertex3f(x * layerWidth + drawPos.x, y + drawPos.y, z * axisStep + drawPos.z);
				glVertex3f(x * layerWidth + drawPos.x + layerWidth, y + drawPos.y, z * axisStep + drawPos.z);
			}
			glEnd();
		}
	}

	// YZ walls
	layerWidth = size.y / layerDensityScale;

	for (double x = 0; x <= size.x; x += size.x) {
		for (double y = 0; y < layerDensityScale; ++y) {
			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(color.r, color.g, color.b);
			for (double z = 0; z <= doubleTrianglesDensityScale; ++z) {
				glVertex3f(x + drawPos.x, y * layerWidth + drawPos.y, z * axisStep + drawPos.z);
				glVertex3f(x + drawPos.x, y * layerWidth + drawPos.y + layerWidth, z * axisStep + drawPos.z);
			}
			glEnd();
		}
	}

	if (size.y > size.x) {
		layerWidth = size.y / layerDensityScale;
		axisStep = size.x / doubleTrianglesDensityScale;

		for (double z = 0; z <= size.z; z += size.z) {
			for (double y = 0; y < layerDensityScale; ++y) {
				glBegin(GL_TRIANGLE_STRIP);
				glColor3f(color.r, color.g, color.b);
				for (double x = 0; x <= doubleTrianglesDensityScale; ++x) {
					glVertex3f(x * axisStep + drawPos.x, y * layerWidth + drawPos.y, z + drawPos.z);
					glVertex3f(x * axisStep + drawPos.x, y * layerWidth + drawPos.y + layerWidth, z + drawPos.z);
				}
				glEnd();
			}
		}
	}
	else {
		layerWidth = size.x / layerDensityScale;
		axisStep = size.y / doubleTrianglesDensityScale;

		for (double z = 0; z <= size.z; z += size.z) {
			for (double x = 0; x < layerDensityScale; ++x) {
				glBegin(GL_TRIANGLE_STRIP);
				glColor3f(color.r, color.g, color.b);
				for (double y = 0; y <= doubleTrianglesDensityScale; ++y) {
					glVertex3f(x * layerWidth + drawPos.x, y * axisStep + drawPos.y, z + drawPos.z);
					glVertex3f(x * layerWidth + drawPos.x + layerWidth, y * axisStep + drawPos.y, z + drawPos.z);
				}
				glEnd();
			}
		}
	}
}