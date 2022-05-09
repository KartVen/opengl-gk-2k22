#pragma once
#include "Cylinder.h"
class Wheel :
    public Cylinder
{
public:
    Wheel(Position center, Size2 size, Color color, char startAxe = 'z');
    void draw();
};

