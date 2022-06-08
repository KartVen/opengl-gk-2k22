#pragma once
#include "Cylinder.h"
class Wheel :
    public Cylinder
{
public:
    Wheel(Vec3 center, Size2 size, Color color, char startAxe = 'z');
    void render(Vec3 pos = { 0,0,0 });
};

