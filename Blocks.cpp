#include "Blocks.h"

Position& Position::operator+(Position value) {
	x += value.x;
	y += value.y;
	z += value.z;
	return *this;
}

Size& Size::operator*(double value) {
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Size& Size::operator*=(double value) {
	return operator*(value);
}

Size2& Size2::operator*(double value) {
	r *= value;
	h *= value;
	return *this;
}

Size2& Size2::operator*=(double value) {
	return operator*(value);
}

void Color::rgb(int r, int g, int b) {
	this->r = (GLdouble)r / 255;
	this->g = (GLdouble)g / 255;
	this->b = (GLdouble)b / 255;
}

void Color::rgb(int rgb) {
	this->r = this->g = this->b = (GLdouble)rgb / 255;
}

void Rotation::rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
	this->angle = angle;
	this->x = x;
	this->y = y;
	this->z = z;
}