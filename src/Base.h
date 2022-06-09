#pragma once
#include <gl\glut.h>
#include <vector>
#include <ostream>

struct Vec3 {
    GLdouble x = 0;
    GLdouble y = 0;
    GLdouble z = 0;
    Vec3& operator+(const Vec3& value);
    Vec3& operator*(double value);
    Vec3& operator*=(double value);
    Vec3& operator+=(const Vec3& value);
    Vec3& operator=(double value);
    friend std::ostream& operator<<(std::ostream& cout, const Vec3& obj);
};

struct Vec2 {
	GLdouble x = 0;
	GLdouble y = 0;
    Vec2& operator+(const Vec2& value);
    Vec2& operator*(double value);
    Vec2& operator*=(double value);
    Vec2& operator+=(const Vec2& value);
    Vec2& operator=(double value);
    friend std::ostream& operator<<(std::ostream& cout, const Vec2& obj);
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

struct Triangle {
    GLdouble x1 = 0;
    GLdouble x2 = 0;
    GLdouble x3 = 0;
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

