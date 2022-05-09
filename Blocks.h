//#include <windows.h>
#include <gl\glut.h>
#include <math.h>

#pragma once

struct Position {
	GLdouble x = 0, y = 0, z = 0;
};

struct Size {
	GLdouble x = 0, y = 0, z = 0;
	Size& operator*(double value);
	Size& operator*=(double value);
};

struct Size2 {
	GLdouble r = 0, h = 0;
	Size2& operator*(double value);
	Size2& operator*=(double value);
};

struct Color {
	GLdouble r = 0, g = 0, b = 0;
	void rgb(int r, int g, int b);
	void rgb(int rgb);
};

struct Rotation {
	GLdouble angle = 0, x = 0, y = 0, z = 0;
	void rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
};

class Blocks
{
public:
	Position pos;
	Color color;
	Rotation rotation;

	virtual void draw() = 0;
};

