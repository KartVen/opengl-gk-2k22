#include "Wheel.h"

Wheel::Wheel(Position center, Size2 size, Color color, char startAxe):
	Cylinder(center, size, color, startAxe)
{}

void Wheel::draw(Position pos)
{
	Cylinder::draw(pos);
}
