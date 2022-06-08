//#include <windows.h>
#include "Base.h"

#pragma once

class Blocks
{
public:
	Vec3 pos;
	Color color;
	Rotation rotation;

	virtual void render(Vec3 pos = { 0,0,0 }) = 0;
};

