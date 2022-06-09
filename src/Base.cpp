#include "Base.h"

Vec3& Vec3::operator+(const Vec3& value) {
	Vec3 newVec = {
		this->x + value.x,
		this->y + value.y,
		this->z + value.z
	};
	return newVec;
}

Vec3& Vec3::operator*(double value) {
	Vec3 newVec = {
		this->x * value,
		this->y * value,
		this->z * value
	};
	return newVec;
}

Vec3& Vec3::operator*=(double value) {
	return operator*(value);
}

Vec3& Vec3::operator+=(const Vec3& value)
{
	return *this + value;
}

Vec3& Vec3::operator=(double value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	return *this;
}

Vec2& Vec2::operator+(const Vec2& value)
{
	Vec2 newVec = {
		   this->x * value.x,
		   this->y * value.y
	};
	return newVec;
}

Vec2& Vec2::operator*(double value) {
	Vec2 newVec = {
		   this->x * value,
		   this->y * value
	};
	return newVec;
}

Vec2& Vec2::operator*=(double value) {
	return operator*(value);
}

Vec2& Vec2::operator+=(const Vec2& value)
{
	return *this + value;
}

Vec2& Vec2::operator=(double value)
{
	this->x = value;
	this->y = value;
	return *this;
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

std::ostream& operator<<(std::ostream& cout, const Vec3& obj)
{
	cout << obj.x << '/' << obj.y << '/' << obj.z;
	return cout;
}

std::ostream& operator<<(std::ostream& cout, const Vec2& obj)
{
	cout << obj.x << '/' << obj.y;
	return cout;
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
