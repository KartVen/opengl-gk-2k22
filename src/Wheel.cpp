#include "Wheel.h"

Wheel::Wheel(Vec3 center, Size2 size, Color color, char startAxe):
	Cylinder(center, size, color, startAxe)
{}

void Wheel::render(Vec3 pos)
{
	Cylinder::render(pos);
}
