# pragma once

#include "Base.h"
#include <vector>

class Model
{
private:
	Vec3 pos;
	std::vector <Vec3> vs;
	std::vector <Vec2> vts;
	std::vector <Vec3> vns;
	std::vector <Face> fs;
public:
	double scale = 1.;
public:
	Model() = default;
	Model(const char* fileName, double scale, Vec3 pos = { 0.,0.,0. });
    void load(const char* fileName);
	void render();
};
